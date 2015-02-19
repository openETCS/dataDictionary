
#include "End_of_Information_Data_Encoder.h"
#include "End_of_Information_Data_UpperBitsNotSet.h"
#include "Bitwalker_Poke_Normal.h"

int End_of_Information_Data_Encoder(Bitstream* stream, const End_of_Information_Data* p)
{
    if (NormalBitstream(stream, END_OF_INFORMATION_DATA_BITSIZE))
    {
        if (End_of_Information_Data_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;


            stream->bitpos += END_OF_INFORMATION_DATA_BITSIZE;


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

