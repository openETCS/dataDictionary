
#include "Level_23_transition_information_Encoder.h"
#include "Level_23_transition_information_UpperBitsNotSet.h"
#include "Bitwalker_Poke_Normal.h"

int Level_23_transition_information_Encoder(Bitstream* stream, const Level_23_transition_information* p)
{
    if (NormalBitstream(stream, LEVEL_23_TRANSITION_INFORMATION_BITSIZE))
    {
        if (Level_23_transition_information_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitwalker_Poke_Normal(addr, size, pos,       13, p->L_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 13,  24, p->NID_LTRBG);

            stream->bitpos += LEVEL_23_TRANSITION_INFORMATION_BITSIZE;

            //@ assert L_PACKET:          EqualBits(stream, pos,       pos + 13,  p->L_PACKET);
            //@ assert NID_LTRBG:         EqualBits(stream, pos + 13,  pos + 37,  p->NID_LTRBG);

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

