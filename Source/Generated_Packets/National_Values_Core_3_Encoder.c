
#include "National_Values_Core_3_Encoder.h"
#include "National_Values_Core_3_UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "National_Values_Core_3_1_Encoder.h"

int National_Values_Core_3_Encoder(Bitstream* stream, const National_Values_Core_3* p)
{
    if (NormalBitstream(stream, NATIONAL_VALUES_CORE_3_CORE_BITSIZE))
    {
        if (National_Values_Core_3_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_NVKVINTSET_k);
            if (p->Q_NVKVINTSET_k == 1)
            {
            Bitstream_Write(stream, 6,  p->A_NVP12_k);
            Bitstream_Write(stream, 6,  p->A_NVP23_k);
            }

            Bitstream_Write(stream, 7,  p->V_NVKVINT_k);
            Bitstream_Write(stream, 7,  p->M_NVKVINT_k);
            Bitstream_Write(stream, 5,  p->N_ITER_3_1);
            for (uint32_t i = 0; i < p->N_ITER_3_1; ++i)
            {
                National_Values_Core_3_1_Encoder(stream, &(p->sub_3_1[i]));
            }



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

