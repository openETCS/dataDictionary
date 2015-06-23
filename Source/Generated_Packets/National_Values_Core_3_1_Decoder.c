
#include "National_Values_Core_3_1_Decoder.h"
#include "Bitstream_Read.h"

int National_Values_Core_3_1_Decoder(Bitstream* stream, National_Values_Core_3_1* p)
{
    if (NormalBitstream(stream, NATIONAL_VALUES_CORE_3_1_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->V_NVKVINT_k_m		= Bitstream_Read(stream, 7); }

	{ p->M_NVKVINT_k_m		= Bitstream_Read(stream, 7); }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

