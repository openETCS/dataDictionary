
#include "National_Values_Core_4_Encoder.h"
#include "National_Values_Core_4_UpperBitsNotSet.h"
#include "Bitstream_Write.h"

int National_Values_Core_4_Encoder(Bitstream* stream, const National_Values_Core_4* p)
{
    if (NormalBitstream(stream, NATIONAL_VALUES_CORE_4_CORE_BITSIZE))
    {
        if (National_Values_Core_4_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 5,  p->L_NVKRINT_l);
            Bitstream_Write(stream, 5,  p->M_NVKRINT_l);



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

