
#include "National_Values_Core_3_Decoder.h"
#include "Bitstream_Read.h"
#include "National_Values_Core_3_1_Decoder.h"

int National_Values_Core_3_Decoder(Bitstream* stream, National_Values_Core_3* p)
{
    if (NormalBitstream(stream, NATIONAL_VALUES_CORE_3_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->Q_NVKVINTSET_k		= Bitstream_Read(stream, 2); }

        if (p->Q_NVKVINTSET_k == 1)
        {
	{ p->A_NVP12_k		= Bitstream_Read(stream, 6); }

	{ p->A_NVP23_k		= Bitstream_Read(stream, 6); }
        }

	{ p->V_NVKVINT_k		= Bitstream_Read(stream, 7); }

	{ p->M_NVKVINT_k		= Bitstream_Read(stream, 7); }

	{ p->N_ITER_3_1		= Bitstream_Read(stream, 5); }

        for (uint32_t i = 0; i < p->N_ITER_3_1; ++i)
        {
            National_Values_Core_3_1_Decoder(stream, &(p->sub_3_1[i]));
        }


	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

