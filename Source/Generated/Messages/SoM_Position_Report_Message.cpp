
#include "SoM_Position_Report_Message.h"
#include "PacketHeader.h"
#include "PacketFactory.h"
#include "Bitstream.h"
#include "Bitwalker.h"
#include <iostream>
#include <cassert>

bool SoM_Position_Report_Message::decode(Bitstream& stream)
{
    uint32_t old_pos = stream.bitpos;

    L_MESSAGE = Bitstream_Read(&stream, 10);
    T_TRAIN = Bitstream_Read(&stream, 32);
    NID_ENGINE = Bitstream_Read(&stream, 24);
    Q_STATUS = Bitstream_Read(&stream, 2);

    PacketHeader packetID;

    ::decode(stream, packetID);
    packet_0_1 = PacketFactory_TrainToTrack(packetID.NID_PACKET);
    packet_0_1->decode(stream);
    if (!packet_0_1)
    {
        return false;
    }

    while (old_pos + (8 * L_MESSAGE) > stream.bitpos + 8 + 7)
    {
        BasePacketPtr packet;

        ::decode(stream, packetID);

        packet = PacketFactory_TrainToTrack(packetID.NID_PACKET);

        packet->decode(stream);
        if (packet)
        {
            if (packet->header.NID_PACKET != 4 &&
                packet->header.NID_PACKET != 5 &&
                packet->header.NID_PACKET != 44)
            {
                return false;
            }
            optional_packets.push_back(packet);
        }
        else
        {
            return false;
        }
    }

    if (stream.bitpos > old_pos + (8 * L_MESSAGE))
    {
        return false;
    }

    stream.bitpos = old_pos + (8 * L_MESSAGE);

    return true;
}

bool SoM_Position_Report_Message::encode(Bitstream& stream) const
{
    uint32_t old_pos = stream.bitpos;

    Bitstream_Write(&stream, 10, L_MESSAGE);
    Bitstream_Write(&stream, 32, T_TRAIN);
    Bitstream_Write(&stream, 24, NID_ENGINE);
    Bitstream_Write(&stream, 2, Q_STATUS);

    if (::encode(stream, packet_0_1->header) != 1)
    {
        return false;
    }
    if (packet_0_1->encode(stream) != 1)
    {
        return false;
    }


    for (auto p = optional_packets.begin(); p != optional_packets.end(); ++p)
    {

        if (::encode(stream, (*p)->header) != 1)
        {
            return false;
        }

        if ((*p)->encode(stream) != 1)
        {
            return false;
        }
    }

    if (stream.bitpos > old_pos + (8 * L_MESSAGE))
    {
        return false;
    }

    stream.bitpos = old_pos + (8 * L_MESSAGE);

    return true;
} 
