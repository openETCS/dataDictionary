
#include "Level_23_transition_information_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int Level_23_transition_information_Decoder(Bitstream* stream, Level_23_transition_information* p)
{
    if (NormalBitstream(stream, LEVEL_23_TRANSITION_INFORMATION_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->NID_PACKET         = Bitwalker_Peek_Normal(addr, size, pos,       8);
        p->L_PACKET           = Bitwalker_Peek_Normal(addr, size, pos + 8,   13);
        p->NID_LTRBG          = Bitwalker_Peek_Normal(addr, size, pos + 21,  24);

        stream->bitpos += LEVEL_23_TRANSITION_INFORMATION_BITSIZE;

        //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
        //@ assert L_PACKET:          EqualBits(stream, pos + 8,   pos + 21,  p->L_PACKET);
        //@ assert NID_LTRBG:         EqualBits(stream, pos + 21,  pos + 45,  p->NID_LTRBG);

        return 1;
    }
    else
    {
        return 0;
    }
}

