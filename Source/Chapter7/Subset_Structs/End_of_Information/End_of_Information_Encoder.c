
#include "End_of_Information_Encoder.h"
#include "End_of_Information_UpperBitsNotSet.h"
#include "Bitwalker_Poke_Normal.h"

int End_of_Information_Encoder(Bitstream* stream, const End_of_Information* p)
{
    if (NormalBitstream(stream, END_OF_INFORMATION_BITSIZE))
    {
        if (End_of_Information_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;


            stream->bitpos += END_OF_INFORMATION_BITSIZE;


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

