
#include "Train_Position_Report_Message.h"
#include "Decoder_Branch.h"
#include "Encoder_Branch.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"


#include <iostream>
#include <cassert>

bool Train_Position_Report_Message::decode(Bitstream& stream)
{
    uint32_t old_pos = stream.bitpos;

    L_MESSAGE = Bitstream_Read(&stream, 10);
    T_TRAIN = Bitstream_Read(&stream, 32);
    NID_ENGINE = Bitstream_Read(&stream, 24);

    PacketHeader packetID;

    PacketHeader_Decoder(&stream, &packetID);
    packet_0_1 = Decoder_Branch_TrainToTrack(stream, packetID);
    if (!packet_0_1)
    {
        return false;
    }

    while (old_pos + (8 * L_MESSAGE) > stream.bitpos + 8 + 7)
    {
        BasePacketPtr packet;

        PacketHeader_Decoder(&stream, &packetID);

        packet = Decoder_Branch_TrainToTrack(stream, packetID);
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

bool Train_Position_Report_Message::encode(Bitstream& stream) const
{
    uint32_t old_pos = stream.bitpos;

    Bitstream_Write(&stream, 10, L_MESSAGE);
    Bitstream_Write(&stream, 32, T_TRAIN);
    Bitstream_Write(&stream, 24, NID_ENGINE);

    if (PacketHeader_Encoder(&stream, &(packet_0_1->header)) != 1)
    {
        return false;
    }
    if (Encoder_Branch_TrainToTrack(stream, packet_0_1) != 1)
    {
        return false;
    }


    for (auto p = optional_packets.begin(); p != optional_packets.end(); ++p)
    {

        if (PacketHeader_Encoder(&stream, &((*p)->header)) != 1)
        {
            return false;
        }

        if (Encoder_Branch_TrainToTrack(stream, *p) != 1)
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
