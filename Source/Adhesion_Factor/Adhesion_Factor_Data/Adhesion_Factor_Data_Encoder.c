
#include "Adhesion_Factor_Data_Encoder.h"
#include "Adhesion_Factor_Data_UpperBitsNotSet.h"
#include "Bitwalker_Poke_Normal.h"

int Adhesion_Factor_Data_Encoder(Bitstream* stream, const Adhesion_Factor_Data* p)
{
    if (NormalBitstream(stream, ADHESION_FACTOR_DATA_BITSIZE))
    {
        if (Adhesion_Factor_Data_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitwalker_Poke_Normal(addr, size, pos,  	 2,  p->Q_SCALE);
            Bitwalker_Poke_Normal(addr, size, pos + 2,   15, p->D_ADHESION);
            Bitwalker_Poke_Normal(addr, size, pos + 17,  15, p->L_ADHESION);
            Bitwalker_Poke_Normal(addr, size, pos + 32,  1,  p->M_ADHESION);

            stream->bitpos += ADHESION_FACTOR_DATA_BITSIZE;

            //@ assert Q_SCALE:           EqualBits(stream, pos,       pos + 2,   p->Q_SCALE);
            //@ assert D_ADHESION:        EqualBits(stream, pos + 2,   pos + 17,  p->D_ADHESION);
            //@ assert L_ADHESION:        EqualBits(stream, pos + 17,  pos + 32,  p->L_ADHESION);
            //@ assert M_ADHESION:        EqualBits(stream, pos + 32,  pos + 33,  p->M_ADHESION);

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

