
#include "Infill_MA_Message.h"
#include "PacketHeader.h"
#include "PacketFactory.h"
#include "Bitstream.h"
#include "Bitwalker.h"
#include <iostream>
#include <cassert>

bool Infill_MA_Message::decode(Bitstream& stream)
{
    uint32_t old_pos = stream.bitpos;

    L_MESSAGE = Bitstream_Read(&stream, 10);
    T_TRAIN = Bitstream_Read(&stream, 32);
    M_ACK = Bitstream_Read(&stream, 1);
    NID_LRBG = Bitstream_Read(&stream, 24);

    PacketHeader packetID;

    ::decode(stream, packetID);
    packet_136 = PacketFactory_TrackToTrain(stream, packetID);
    packet_136->decode(stream);
    if (!packet_136)
    {
        return false;
    }

    ::decode(stream, packetID);
    packet_12 = PacketFactory_TrackToTrain(stream, packetID);
    packet_12->decode(stream);
    if (!packet_12)
    {
        return false;
    }

    while (old_pos + (8 * L_MESSAGE) > stream.bitpos + 8 + 7)
    {
        BasePacketPtr packet;

        ::decode(stream, packetID);

        packet = PacketFactory_TrackToTrain(stream, packetID);

        packet->decode(stream);
        if (packet)
        {
            if (packet->header.NID_PACKET != 5 &&
                packet->header.NID_PACKET != 21 &&
                packet->header.NID_PACKET != 27 &&
                packet->header.NID_PACKET != 39 &&
                packet->header.NID_PACKET != 40 &&
                packet->header.NID_PACKET != 41 &&
                packet->header.NID_PACKET != 44 &&
                packet->header.NID_PACKET != 49 &&
                packet->header.NID_PACKET != 51 &&
                packet->header.NID_PACKET != 65 &&
                packet->header.NID_PACKET != 66 &&
                packet->header.NID_PACKET != 68 &&
                packet->header.NID_PACKET != 69 &&
                packet->header.NID_PACKET != 70 &&
                packet->header.NID_PACKET != 71 &&
                packet->header.NID_PACKET != 80 &&
                packet->header.NID_PACKET != 88 &&
                packet->header.NID_PACKET != 138 &&
                packet->header.NID_PACKET != 139)
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

bool Infill_MA_Message::encode(Bitstream& stream) const
{
    uint32_t old_pos = stream.bitpos;

    Bitstream_Write(&stream, 10, L_MESSAGE);
    Bitstream_Write(&stream, 32, T_TRAIN);
    Bitstream_Write(&stream, 1, M_ACK);
    Bitstream_Write(&stream, 24, NID_LRBG);

    if (::encode(stream, packet_136->header) != 1)
    {
        return false;
    }
    if (packet_136->encode(stream) != 1)
    {
        return false;
    }

    if (::encode(stream, packet_12->header) != 1)
    {
        return false;
    }
    if (packet_12->encode(stream) != 1)
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
