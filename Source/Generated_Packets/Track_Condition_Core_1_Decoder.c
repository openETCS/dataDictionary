
#include "Track_Condition_Core_1_Decoder.h"
#include "Bitstream_Read.h"

int Track_Condition_Core_1_Decoder(Bitstream* stream, Track_Condition_Core_1* p)
{
    if (NormalBitstream(stream, TRACK_CONDITION_CORE_1_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->D_TRACKCOND_k		= Bitstream_Read(stream, 15); }

	{ p->L_TRACKCOND_k		= Bitstream_Read(stream, 15); }

	{ p->M_TRACKCOND_k		= Bitstream_Read(stream, 4); }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

