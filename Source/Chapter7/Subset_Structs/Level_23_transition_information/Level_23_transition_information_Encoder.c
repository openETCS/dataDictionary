
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

            Bitwalker_Poke_Normal(addr, size, pos,       8,  p->NID_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 8,   13, p->L_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 21,  24, p->NID_LTRBG);

            stream->bitpos += LEVEL_23_TRANSITION_INFORMATION_BITSIZE;

            //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
            //@ assert L_PACKET:          EqualBits(stream, pos + 8,   pos + 21,  p->L_PACKET);
            //@ assert NID_LTRBG:         EqualBits(stream, pos + 21,  pos + 45,  p->NID_LTRBG);

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

