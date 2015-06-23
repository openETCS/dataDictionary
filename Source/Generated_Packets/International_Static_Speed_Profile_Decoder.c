
#include "International_Static_Speed_Profile_Decoder.h"
#include "Bitstream_Read.h"
#include "International_Static_Speed_Profile_Core_1_Decoder.h"
#include "International_Static_Speed_Profile_Core_2_Decoder.h"

int International_Static_Speed_Profile_Decoder(Bitstream* stream, International_Static_Speed_Profile_Core* p)
{
    if (NormalBitstream(stream, INTERNATIONAL_STATIC_SPEED_PROFILE_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->Q_DIR		= Bitstream_Read(stream, 2); }

	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	{ p->Q_SCALE		= Bitstream_Read(stream, 2); }

	{ p->D_STATIC		= Bitstream_Read(stream, 15); }

	{ p->V_STATIC		= Bitstream_Read(stream, 7); }

	{ p->Q_FRONT		= Bitstream_Read(stream, 1); }

	{ p->N_ITER_1		= Bitstream_Read(stream, 5); }

        for (uint32_t i = 0; i < p->N_ITER_1; ++i)
        {
            International_Static_Speed_Profile_Core_1_Decoder(stream, &(p->sub_1[i]));
        }
	{ p->N_ITER_2		= Bitstream_Read(stream, 5); }

        for (uint32_t i = 0; i < p->N_ITER_2; ++i)
        {
            International_Static_Speed_Profile_Core_2_Decoder(stream, &(p->sub_2[i]));
        }


	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

