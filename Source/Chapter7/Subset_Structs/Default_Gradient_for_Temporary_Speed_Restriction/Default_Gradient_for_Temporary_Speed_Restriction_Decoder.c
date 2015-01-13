
#include "Default_Gradient_for_Temporary_Speed_Restriction_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int Default_Gradient_for_Temporary_Speed_Restriction_Decoder(Bitstream* stream, Default_Gradient_for_Temporary_Speed_Restriction* p)
{
    if (NormalBitstream(stream, DEFAULT_GRADIENT_FOR_TEMPORARY_SPEED_RESTRICTION_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->NID_PACKET         = Bitwalker_Peek_Normal(addr, size, pos,       8);
        p->Q_DIR              = Bitwalker_Peek_Normal(addr, size, pos + 8,   2);
        p->L_PACKET           = Bitwalker_Peek_Normal(addr, size, pos + 10,  13);
        p->Q_GDIR             = Bitwalker_Peek_Normal(addr, size, pos + 23,  1);
        p->G_TSR              = Bitwalker_Peek_Normal(addr, size, pos + 24,  8);

        stream->bitpos += DEFAULT_GRADIENT_FOR_TEMPORARY_SPEED_RESTRICTION_BITSIZE;

        //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
        //@ assert Q_DIR:             EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET);
        //@ assert Q_GDIR:            EqualBits(stream, pos + 23,  pos + 24,  p->Q_GDIR);
        //@ assert G_TSR:             EqualBits(stream, pos + 24,  pos + 32,  p->G_TSR);

        return 1;
    }
    else
    {
        return 0;
    }
}

