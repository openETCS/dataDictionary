
#include "Gradient_Profile_Core_1_Decoder.h"
#include "Bitstream_Read.h"

int Gradient_Profile_Core_1_Decoder(Bitstream* stream, Gradient_Profile_Core_1* p)
{
    if (NormalBitstream(stream, GRADIENT_PROFILE_CORE_1_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->D_GRADIENT_k		= Bitstream_Read(stream, 15); }

	{ p->Q_GDIR_k		= Bitstream_Read(stream, 1); }

	{ p->G_A_k		= Bitstream_Read(stream, 8); }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

