
#include "Level_23_transition_information_Data_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int Level_23_transition_information_Data_Decoder(Bitstream* stream, Level_23_transition_information_Data* p)
{
    if (NormalBitstream(stream, LEVEL_23_TRANSITION_INFORMATION_DATA_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->NID_LTRBG          = Bitwalker_Peek_Normal(addr, size, pos,       24);

        stream->bitpos += LEVEL_23_TRANSITION_INFORMATION_DATA_BITSIZE;

        //@ assert NID_LTRBG:         EqualBits(stream, pos,       pos + 24,  p->NID_LTRBG);

        //@ assert NID_LTRBG:         UpperBitsNotSet(p->NID_LTRBG,         24);

        return 1;
    }
    else
    {
        return 0;
    }
}

