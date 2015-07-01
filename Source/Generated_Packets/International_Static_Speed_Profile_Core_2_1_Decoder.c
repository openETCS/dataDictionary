
#include "International_Static_Speed_Profile_Core_2_1_Decoder.h"
#include "Bitstream_Read.h"

int International_Static_Speed_Profile_Core_2_1_Decoder(Bitstream* stream, International_Static_Speed_Profile_Core_2_1* p)
{
    if (NormalBitstream(stream, INTERNATIONAL_STATIC_SPEED_PROFILE_CORE_2_1_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->Q_DIFF_k_m		= Bitstream_Read(stream, 2); }

        if (p->Q_DIFF_k_m == 0)
        {
	{ p->NC_CDDIFF_k_m		= Bitstream_Read(stream, 4); }
        }

        if ((p->Q_DIFF_k_m == 1) || (p->Q_DIFF_k_m == 2))
        {
	{ p->NC_DIFF_k_m		= Bitstream_Read(stream, 4); }
        }

	{ p->V_DIFF_k_m		= Bitstream_Read(stream, 7); }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

