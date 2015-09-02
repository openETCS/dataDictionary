
#include "Track_Ahead_Free_Request_Message.h"
#include "Packet_Header.h"
#include "Decoder_Branch.h"
#include "Encoder_Branch.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

#include "Bitwalker_Read.h"
#include <iostream>
#include <cassert>

bool Track_Ahead_Free_Request_Message::decode(Bitstream& stream)
{
    uint32_t old_pos = stream.bitpos;

    L_MESSAGE = Bitstream_Read(&stream, 10);
    T_TRAIN = Bitstream_Read(&stream, 32);
    M_ACK = Bitstream_Read(&stream, 1);
    NID_LRBG = Bitstream_Read(&stream, 24);
    Q_SCALE = Bitstream_Read(&stream, 2);
    D_REF = Bitstream_Read(&stream, 16);
    Q_DIR = Bitstream_Read(&stream, 2);
    D_TAFDISPLAY = Bitstream_Read(&stream, 15);
    L_TAFDISPLAY = Bitstream_Read(&stream, 15);

    if (stream.bitpos > old_pos + (8 * L_MESSAGE))
    {
        return false;
    }

    stream.bitpos = old_pos + (8 * L_MESSAGE);

    return true;
}

bool Track_Ahead_Free_Request_Message::encode(Bitstream& stream) const
{
    uint32_t old_pos = stream.bitpos;

    Bitstream_Write(&stream, 10, L_MESSAGE);
    Bitstream_Write(&stream, 32, T_TRAIN);
    Bitstream_Write(&stream, 1, M_ACK);
    Bitstream_Write(&stream, 24, NID_LRBG);
    Bitstream_Write(&stream, 2, Q_SCALE);
    Bitstream_Write(&stream, 16, D_REF);
    Bitstream_Write(&stream, 2, Q_DIR);
    Bitstream_Write(&stream, 15, D_TAFDISPLAY);
    Bitstream_Write(&stream, 15, L_TAFDISPLAY);

    if (stream.bitpos > old_pos + (8 * L_MESSAGE))
    {
        return false;
    }

    stream.bitpos = old_pos + (8 * L_MESSAGE);

    return true;
} 
