
#include "Request_to_shorten_MA_is_rejected_Message.h"
#include "Decoder_Branch.h"
#include "Encoder_Branch.h"


#include <iostream>
#include <cassert>

bool Request_to_shorten_MA_is_rejected_Message::decode(Bitstream& stream)
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

    if (stream.bitpos > old_pos + (8 * L_MESSAGE))
    {
        return false;
    }

    stream.bitpos = old_pos + (8 * L_MESSAGE);

    return true;
}

bool Request_to_shorten_MA_is_rejected_Message::encode(Bitstream& stream) const
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

    if (stream.bitpos > old_pos + (8 * L_MESSAGE))
    {
        return false;
    }

    stream.bitpos = old_pos + (8 * L_MESSAGE);

    return true;
}
