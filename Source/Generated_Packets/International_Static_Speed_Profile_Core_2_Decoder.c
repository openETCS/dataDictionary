
#include "International_Static_Speed_Profile_Core_2_Decoder.h"
#include "Bitstream_Read.h"
#include "International_Static_Speed_Profile_Core_2_1_Decoder.h"

int International_Static_Speed_Profile_Core_2_Decoder(Bitstream* stream, International_Static_Speed_Profile_Core_2* p)
{
    if (NormalBitstream(stream, INTERNATIONAL_STATIC_SPEED_PROFILE_CORE_2_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->D_STATIC_k		= Bitstream_Read(stream, 15); }

	{ p->V_STATIC_k		= Bitstream_Read(stream, 7); }

	{ p->Q_FRONT_k		= Bitstream_Read(stream, 1); }

	{ p->N_ITER_2_1		= Bitstream_Read(stream, 5); }

        for (uint32_t i = 0; i < p->N_ITER_2_1; ++i)
        {
            International_Static_Speed_Profile_Core_2_1_Decoder(stream, &(p->sub_2_1[i]));
        }


	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

