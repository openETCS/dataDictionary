
#include "SH_Refused_Message.h"
#include "Decoder_Branch.h"
#include "Encoder_Branch.h"


#include <iostream>
#include <cassert>

bool SH_Refused_Message::decode(Bitstream& stream)
{
    uint32_t old_pos = stream.bitpos;

    L_MESSAGE = Bitstream_Read(&stream, 10);
    T_TRAIN_0 = Bitstream_Read(&stream, 32);
    M_ACK = Bitstream_Read(&stream, 1);
    NID_LRBG = Bitstream_Read(&stream, 24);
    T_TRAIN_1 = Bitstream_Read(&stream, 32);

    if (stream.bitpos > old_pos + (8 * L_MESSAGE))
    {
        return false;
    }

    stream.bitpos = old_pos + (8 * L_MESSAGE);

    return true;
}

bool SH_Refused_Message::encode(Bitstream& stream) const
{
    uint32_t old_pos = stream.bitpos;

    Bitstream_Write(&stream, 10, L_MESSAGE);
    Bitstream_Write(&stream, 32, T_TRAIN_0);
    Bitstream_Write(&stream, 1, M_ACK);
    Bitstream_Write(&stream, 24, NID_LRBG);
    Bitstream_Write(&stream, 32, T_TRAIN_1);

    if (stream.bitpos > old_pos + (8 * L_MESSAGE))
    {
        return false;
    }

    stream.bitpos = old_pos + (8 * L_MESSAGE);

    return true;
} 
