
#include "Level_23_transition_information_Data_Encoder.h"
#include "Level_23_transition_information_Data_UpperBitsNotSet.h"
#include "Bitwalker_Poke_Normal.h"

int Level_23_transition_information_Data_Encoder(Bitstream* stream, const Level_23_transition_information_Data* p)
{
    if (NormalBitstream(stream, LEVEL_23_TRANSITION_INFORMATION_DATA_BITSIZE))
    {
        if (Level_23_transition_information_Data_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitwalker_Poke_Normal(addr, size, pos,       24, p->NID_LTRBG);

            stream->bitpos += LEVEL_23_TRANSITION_INFORMATION_DATA_BITSIZE;

            //@ assert NID_LTRBG:         EqualBits(stream, pos,       pos + 24,  p->NID_LTRBG);

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

