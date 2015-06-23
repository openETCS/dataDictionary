
#include "Permitted_Braking_Distance_Information_Core_1_Decoder.h"
#include "Bitstream_Read.h"

int Permitted_Braking_Distance_Information_Core_1_Decoder(Bitstream* stream, Permitted_Braking_Distance_Information_Core_1* p)
{
    if (NormalBitstream(stream, PERMITTED_BRAKING_DISTANCE_INFORMATION_CORE_1_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->D_PBD_k		= Bitstream_Read(stream, 15); }

	{ p->Q_GDIR_k		= Bitstream_Read(stream, 1); }

	{ p->G_PBDSR_k		= Bitstream_Read(stream, 8); }

	{ p->Q_PBDSR_k		= Bitstream_Read(stream, 1); }

	{ p->D_PBDSR_k		= Bitstream_Read(stream, 15); }

	{ p->L_PBDSR_k		= Bitstream_Read(stream, 15); }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

