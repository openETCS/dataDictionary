
#include "Temporary_Speed_Restriction_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int Temporary_Speed_Restriction_Decoder(Bitstream* stream, Temporary_Speed_Restriction* p)
{
    if (NormalBitstream(stream, TEMPORARY_SPEED_RESTRICTION_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->NID_PACKET         = Bitwalker_Peek_Normal(addr, size, pos,       8);
        p->Q_DIR              = Bitwalker_Peek_Normal(addr, size, pos + 8,   2);
        p->L_PACKET           = Bitwalker_Peek_Normal(addr, size, pos + 10,  13);
        p->Q_SCALE            = Bitwalker_Peek_Normal(addr, size, pos + 23,  2);
        p->NID_TSR            = Bitwalker_Peek_Normal(addr, size, pos + 25,  8);
        p->D_TSR              = Bitwalker_Peek_Normal(addr, size, pos + 33,  15);
        p->L_TSR              = Bitwalker_Peek_Normal(addr, size, pos + 48,  15);
        p->Q_FRONT            = Bitwalker_Peek_Normal(addr, size, pos + 63,  1);
        p->V_TSR              = Bitwalker_Peek_Normal(addr, size, pos + 64,  7);

        stream->bitpos += TEMPORARY_SPEED_RESTRICTION_BITSIZE;

        //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
        //@ assert Q_DIR:             EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET);
        //@ assert Q_SCALE:           EqualBits(stream, pos + 23,  pos + 25,  p->Q_SCALE);
        //@ assert NID_TSR:           EqualBits(stream, pos + 25,  pos + 33,  p->NID_TSR);
        //@ assert D_TSR:             EqualBits(stream, pos + 33,  pos + 48,  p->D_TSR);
        //@ assert L_TSR:             EqualBits(stream, pos + 48,  pos + 63,  p->L_TSR);
        //@ assert Q_FRONT:           EqualBits(stream, pos + 63,  pos + 64,  p->Q_FRONT);
        //@ assert V_TSR:             EqualBits(stream, pos + 64,  pos + 71,  p->V_TSR);

        return 1;
    }
    else
    {
        return 0;
    }
}

