
#include "Repositioning_Information_Data_Encoder.h"
#include "Repositioning_Information_Data_UpperBitsNotSet.h"
#include "Bitwalker_Poke_Normal.h"

int Repositioning_Information_Data_Encoder(Bitstream* stream, const Repositioning_Information_Data* p)
{
    if (NormalBitstream(stream, REPOSITIONING_INFORMATION_DATA_BITSIZE))
    {
        if (Repositioning_Information_Data_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitwalker_Poke_Normal(addr, size, pos,       2,  p->Q_DIR);
            Bitwalker_Poke_Normal(addr, size, pos + 15,  2,  p->Q_SCALE);
            Bitwalker_Poke_Normal(addr, size, pos + 17,  15, p->L_SECTION);

            stream->bitpos += REPOSITIONING_INFORMATION_DATA_BITSIZE;

            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
            //@ assert L_SECTION:         EqualBits(stream, pos + 17,  pos + 32,  p->L_SECTION);

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

