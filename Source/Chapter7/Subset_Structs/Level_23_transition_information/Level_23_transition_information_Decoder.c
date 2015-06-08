
#include "Level_23_transition_information_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int Level_23_transition_information_Decoder(Bitstream* stream, Level_23_transition_information* p)
{
    if (NormalBitstream(stream, LEVEL_23_TRANSITION_INFORMATION_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->L_PACKET           = Bitwalker_Peek_Normal(addr, size, pos,       13);
        p->NID_LTRBG          = Bitwalker_Peek_Normal(addr, size, pos + 13,  24);

        stream->bitpos += LEVEL_23_TRANSITION_INFORMATION_BITSIZE;

        //@ assert L_PACKET:          EqualBits(stream, pos,       pos + 13,  p->L_PACKET);
        //@ assert NID_LTRBG:         EqualBits(stream, pos + 13,  pos + 37,  p->NID_LTRBG);

        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert NID_LTRBG:         UpperBitsNotSet(p->NID_LTRBG,         24);

        return 1;
    }
    else
    {
        return 0;
    }
}

