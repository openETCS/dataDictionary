
#include "Gradient_Profile_Decoder.h"
#include "Bitstream_Read.h"
#include "Gradient_Profile_Core_1_Decoder.h"

int Gradient_Profile_Decoder(Bitstream* stream, Gradient_Profile_Core* p)
{
    if (NormalBitstream(stream, GRADIENT_PROFILE_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->Q_DIR		= Bitstream_Read(stream, 2); }

	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	{ p->Q_SCALE		= Bitstream_Read(stream, 2); }

	{ p->D_GRADIENT		= Bitstream_Read(stream, 15); }

	{ p->Q_GDIR		= Bitstream_Read(stream, 1); }

	{ p->G_A		= Bitstream_Read(stream, 8); }

	{ p->N_ITER_1		= Bitstream_Read(stream, 5); }

        for (uint32_t i = 0; i < p->N_ITER_1; ++i)
        {
            Gradient_Profile_Core_1_Decoder(stream, &(p->sub_1[i]));
        }


	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

