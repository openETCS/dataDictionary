
#include "Reversing_area_information_Data_Encoder.h"
#include "Reversing_area_information_Data_UpperBitsNotSet.h"
#include "Bitwalker_Poke_Normal.h"

int Reversing_area_information_Data_Encoder(Bitstream* stream, const Reversing_area_information_Data* p)
{
    if (NormalBitstream(stream, REVERSING_AREA_INFORMATION_DATA_BITSIZE))
    {
        if (Reversing_area_information_Data_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitwalker_Poke_Normal(addr, size, pos,       2,  p->Q_DIR);
            Bitwalker_Poke_Normal(addr, size, pos + 15,  2,  p->Q_SCALE);
            Bitwalker_Poke_Normal(addr, size, pos + 17,  15, p->D_STARTREVERSE);
            Bitwalker_Poke_Normal(addr, size, pos + 32,  15, p->L_REVERSEAREA);

            stream->bitpos += REVERSING_AREA_INFORMATION_DATA_BITSIZE;

            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
            //@ assert D_STARTREVERSE:    EqualBits(stream, pos + 17,  pos + 32,  p->D_STARTREVERSE);
            //@ assert L_REVERSEAREA:     EqualBits(stream, pos + 32,  pos + 47,  p->L_REVERSEAREA);

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

