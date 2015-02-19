
#include "Temporary_Speed_Restriction_Data_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int Temporary_Speed_Restriction_Data_Decoder(Bitstream* stream, Temporary_Speed_Restriction_Data* p)
{
    if (NormalBitstream(stream, TEMPORARY_SPEED_RESTRICTION_DATA_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->Q_DIR              = Bitwalker_Peek_Normal(addr, size, pos,       2);
        p->Q_SCALE            = Bitwalker_Peek_Normal(addr, size, pos + 15,  2);
        p->NID_TSR            = Bitwalker_Peek_Normal(addr, size, pos + 17,  8);
        p->D_TSR              = Bitwalker_Peek_Normal(addr, size, pos + 25,  15);
        p->L_TSR              = Bitwalker_Peek_Normal(addr, size, pos + 40,  15);
        p->Q_FRONT            = Bitwalker_Peek_Normal(addr, size, pos + 55,  1);
        p->V_TSR              = Bitwalker_Peek_Normal(addr, size, pos + 56,  7);

        stream->bitpos += TEMPORARY_SPEED_RESTRICTION_DATA_BITSIZE;

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
        //@ assert NID_TSR:           EqualBits(stream, pos + 17,  pos + 25,  p->NID_TSR);
        //@ assert D_TSR:             EqualBits(stream, pos + 25,  pos + 40,  p->D_TSR);
        //@ assert L_TSR:             EqualBits(stream, pos + 40,  pos + 55,  p->L_TSR);
        //@ assert Q_FRONT:           EqualBits(stream, pos + 55,  pos + 56,  p->Q_FRONT);
        //@ assert V_TSR:             EqualBits(stream, pos + 56,  pos + 63,  p->V_TSR);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert Q_SCALE:           UpperBitsNotSet(p->Q_SCALE,           2);
        //@ assert NID_TSR:           UpperBitsNotSet(p->NID_TSR,           8);
        //@ assert D_TSR:             UpperBitsNotSet(p->D_TSR,             15);
        //@ assert L_TSR:             UpperBitsNotSet(p->L_TSR,             15);
        //@ assert Q_FRONT:           UpperBitsNotSet(p->Q_FRONT,           1);
        //@ assert V_TSR:             UpperBitsNotSet(p->V_TSR,             7);

        return 1;
    }
    else
    {
        return 0;
    }
}

