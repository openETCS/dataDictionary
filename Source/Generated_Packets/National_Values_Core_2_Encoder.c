
#include "National_Values_Core_2_Encoder.h"
#include "National_Values_Core_2_UpperBitsNotSet.h"
#include "Bitstream_Write.h"

int National_Values_Core_2_Encoder(Bitstream* stream, const National_Values_Core_2* p)
{
    if (NormalBitstream(stream, NATIONAL_VALUES_CORE_2_CORE_BITSIZE))
    {
        if (National_Values_Core_2_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 7,  p->V_NVKVINT_n);
            Bitstream_Write(stream, 7,  p->M_NVKVINT_n);



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

