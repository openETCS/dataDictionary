
#include "National_Values_Core_2_Decoder.h"
#include "Bitstream_Read.h"

int National_Values_Core_2_Decoder(Bitstream* stream, National_Values_Core_2* p)
{
    if (NormalBitstream(stream, NATIONAL_VALUES_CORE_2_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->V_NVKVINT_n		= Bitstream_Read(stream, 7); }

	{ p->M_NVKVINT_n		= Bitstream_Read(stream, 7); }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

