
#include "Adhesion_Factor_Encoder.h"
#include "Adhesion_Factor_UpperBitsNotSet.h"
#include "Bitwalker_Poke_Normal.h"

int Adhesion_Factor_Encoder(Bitstream* stream, const Adhesion_Factor* p)
{
    if (NormalBitstream(stream, ADHESION_FACTOR_BITSIZE))
    {
        if (Adhesion_Factor_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitwalker_Poke_Normal(addr, size, pos,  	 2,  p->data.Q_SCALE);
            Bitwalker_Poke_Normal(addr, size, pos + 2,   15, p->data.D_ADHESION);
            Bitwalker_Poke_Normal(addr, size, pos + 17,  15, p->data.L_ADHESION);
            Bitwalker_Poke_Normal(addr, size, pos + 32,  1,  p->data.M_ADHESION);

            stream->bitpos += ADHESION_FACTOR_BITSIZE;

            //@ assert Q_SCALE:           EqualBits(stream, pos + 23,  pos + 25,  p->data.Q_SCALE);
            //@ assert D_ADHESION:        EqualBits(stream, pos + 25,  pos + 40,  p->data.D_ADHESION);
            //@ assert L_ADHESION:        EqualBits(stream, pos + 40,  pos + 55,  p->data.L_ADHESION);
            //@ assert M_ADHESION:        EqualBits(stream, pos + 55,  pos + 56,  p->data.M_ADHESION);

            return 1;
        }
        else
        {
            return -2;
        }
    }
    else
    {
        return -1;
    }
}

