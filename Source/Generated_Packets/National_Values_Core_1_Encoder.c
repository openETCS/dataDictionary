
#include "National_Values_Core_1_Encoder.h"
#include "National_Values_Core_1_UpperBitsNotSet.h"
#include "Bitstream_Write.h"

int National_Values_Core_1_Encoder(Bitstream* stream, const National_Values_Core_1* p)
{
    if (NormalBitstream(stream, NATIONAL_VALUES_CORE_1_CORE_BITSIZE))
    {
        if (National_Values_Core_1_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 10, p->NID_C_p);


            //@ assert NID_C_p:           EqualBits(stream, pos + 47,  pos + 57,  p->NID_C_p);

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

