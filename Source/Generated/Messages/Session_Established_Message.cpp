
#include "Session_Established_Message.h"
#include "Decoder_Branch.h"
#include "Encoder_Branch.h"


#include <iostream>
#include <cassert>

bool Session_Established_Message::decode(Bitstream& stream)
{
    uint32_t old_pos = stream.bitpos;

    L_MESSAGE = Bitstream_Read(&stream, 10);
    T_TRAIN = Bitstream_Read(&stream, 32);
    NID_ENGINE = Bitstream_Read(&stream, 24);

    PacketHeader packetID;

    while (old_pos + (8 * L_MESSAGE) > stream.bitpos + 8 + 7)
    {
        BasePacketPtr packet;

        PacketHeader_Decoder(&stream, &packetID);

        packet = Decoder_Branch_TrainToTrack(stream, packetID);
        if (packet)
        {
            if (packet->header.NID_PACKET != 3)
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

bool Session_Established_Message::encode(Bitstream& stream) const
{
    uint32_t old_pos = stream.bitpos;

    Bitstream_Write(&stream, 10, L_MESSAGE);
    Bitstream_Write(&stream, 32, T_TRAIN);
    Bitstream_Write(&stream, 24, NID_ENGINE);


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
