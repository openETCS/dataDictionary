
#include "National_Values_Core_3_1_Encoder.h"
#include "National_Values_Core_3_1_UpperBitsNotSet.h"
#include "Bitstream_Write.h"

int National_Values_Core_3_1_Encoder(Bitstream* stream, const National_Values_Core_3_1* p)
{
    if (NormalBitstream(stream, NATIONAL_VALUES_CORE_3_1_CORE_BITSIZE))
    {
        if (National_Values_Core_3_1_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 7,  p->V_NVKVINT_k_m);
            Bitstream_Write(stream, 7,  p->M_NVKVINT_k_m);



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

