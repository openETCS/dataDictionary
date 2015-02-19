
#include "Danger_for_Shunting_information_Data_Encoder.h"
#include "Danger_for_Shunting_information_Data_UpperBitsNotSet.h"
#include "Bitwalker_Poke_Normal.h"

int Danger_for_Shunting_information_Data_Encoder(Bitstream* stream, const Danger_for_Shunting_information_Data* p)
{
    if (NormalBitstream(stream, DANGER_FOR_SHUNTING_INFORMATION_DATA_BITSIZE))
    {
        if (Danger_for_Shunting_information_Data_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitwalker_Poke_Normal(addr, size, pos,       2,  p->Q_DIR);
            Bitwalker_Poke_Normal(addr, size, pos + 15,  1,  p->Q_ASPECT);

            stream->bitpos += DANGER_FOR_SHUNTING_INFORMATION_DATA_BITSIZE;

            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert Q_ASPECT:          EqualBits(stream, pos + 15,  pos + 16,  p->Q_ASPECT);

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

