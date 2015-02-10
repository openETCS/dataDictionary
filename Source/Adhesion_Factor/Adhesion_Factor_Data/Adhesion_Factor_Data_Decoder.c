
#include "Adhesion_Factor_Data_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int Adhesion_Factor_Data_Decoder(Bitstream* stream, Adhesion_Factor_Data* p)
{
    if (NormalBitstream(stream, ADHESION_FACTOR_DATA_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->Q_SCALE            = Bitwalker_Peek_Normal(addr, size, pos,       2);
        p->D_ADHESION         = Bitwalker_Peek_Normal(addr, size, pos + 2,   15);
        p->L_ADHESION         = Bitwalker_Peek_Normal(addr, size, pos + 17,  15);
        p->M_ADHESION         = Bitwalker_Peek_Normal(addr, size, pos + 32,  1);

        stream->bitpos += ADHESION_FACTOR_DATA_BITSIZE;

        //@ assert Q_SCALE:           EqualBits(stream, pos,       pos + 2,   p->Q_SCALE);
        //@ assert D_ADHESION:        EqualBits(stream, pos + 2,   pos + 17,  p->D_ADHESION);
        //@ assert L_ADHESION:        EqualBits(stream, pos + 17,  pos + 32,  p->L_ADHESION);
        //@ assert M_ADHESION:        EqualBits(stream, pos + 32,  pos + 33,  p->M_ADHESION);

        return 1;
    }
    else
    {
        return 0;
    }
}

