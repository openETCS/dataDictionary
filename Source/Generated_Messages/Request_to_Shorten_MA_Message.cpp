
#include "Request_to_Shorten_MA_Message.h"
#include "Packet_Header.h"
#include "Decoder_Branch.h"
#include "Encoder_Branch.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

#include "Bitwalker_Peek_Normal.h"
#include <iostream>
#include <cassert>

bool Request_to_Shorten_MA_Message::decode(Bitstream& stream)
{
    uint32_t old_pos = stream.bitpos;

    L_MESSAGE = Bitstream_Read(&stream, 10);
    T_TRAIN = Bitstream_Read(&stream, 32);
    M_ACK = Bitstream_Read(&stream, 1);
    NID_LRBG = Bitstream_Read(&stream, 24);

    Packet_Header_Decoder(&stream, &packetID);
    packet_15 = Decoder_Branch_TrackToTrain(stream, packetID);
    if (!packet_15)
    {
        return false;
    }

    Packet_Header_Decoder(&stream, &packetID);
    packet_80 = Decoder_Branch_TrackToTrain(stream, packetID);
    if (!packet_80)
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

bool Request_to_Shorten_MA_Message::encode(Bitstream& stream) const
{
    uint32_t old_pos = stream.bitpos;

    Bitstream_Write(&stream, 10, L_MESSAGE);
    Bitstream_Write(&stream, 32, T_TRAIN);
    Bitstream_Write(&stream, 1, M_ACK);
    Bitstream_Write(&stream, 24, NID_LRBG);

    if (Packet_Header_Encoder(&stream, &(packet_15->header)) != 1)
    {
        return false;
    }
    if (Encoder_Branch_TrackToTrain(stream, packet_15) != 1)
    {
        return false;
    }

    if (Packet_Header_Encoder(&stream, &(packet_80->header)) != 1)
    {
        return false;
    }
    if (Encoder_Branch_TrackToTrain(stream, packet_80) != 1)
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
