
#include "National_Values_Core_4_Decoder.h"
#include "Bitstream_Read.h"

int National_Values_Core_4_Decoder(Bitstream* stream, National_Values_Core_4* p)
{
    if (NormalBitstream(stream, NATIONAL_VALUES_CORE_4_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->L_NVKRINT_l		= Bitstream_Read(stream, 5); }

	{ p->M_NVKRINT_l		= Bitstream_Read(stream, 5); }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

