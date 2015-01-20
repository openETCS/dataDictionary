
#include "Adhesion_Factor_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int Adhesion_Factor_Decoder(Bitstream* stream, Adhesion_Factor* p)
{
    if (NormalBitstream(stream, ADHESION_FACTOR_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->data.Q_SCALE            = Bitwalker_Peek_Normal(addr, size, pos,       2);
        p->data.D_ADHESION         = Bitwalker_Peek_Normal(addr, size, pos + 2,   15);
        p->data.L_ADHESION         = Bitwalker_Peek_Normal(addr, size, pos + 17,  15);
        p->data.M_ADHESION         = Bitwalker_Peek_Normal(addr, size, pos + 32,  1);

        stream->bitpos += ADHESION_FACTOR_BITSIZE;

        //@ assert Q_SCALE:           EqualBits(stream, pos,       pos + 2,   p->data.Q_SCALE);
        //@ assert D_ADHESION:        EqualBits(stream, pos + 2,   pos + 17,  p->data.D_ADHESION);
        //@ assert L_ADHESION:        EqualBits(stream, pos + 17,  pos + 32,  p->data.L_ADHESION);
        //@ assert M_ADHESION:        EqualBits(stream, pos + 32,  pos + 33,  p->data.M_ADHESION);

        return 1;
    }
    else
    {
        return 0;
    }
}

