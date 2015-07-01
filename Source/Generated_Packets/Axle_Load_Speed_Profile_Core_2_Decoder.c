
#include "Axle_Load_Speed_Profile_Core_2_Decoder.h"
#include "Bitstream_Read.h"
#include "Axle_Load_Speed_Profile_Core_2_1_Decoder.h"

int Axle_Load_Speed_Profile_Core_2_Decoder(Bitstream* stream, Axle_Load_Speed_Profile_Core_2* p)
{
    if (NormalBitstream(stream, AXLE_LOAD_SPEED_PROFILE_CORE_2_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->D_AXLELOAD_k		= Bitstream_Read(stream, 15); }

	{ p->L_AXLELOAD_k		= Bitstream_Read(stream, 15); }

	{ p->Q_FRONT_k		= Bitstream_Read(stream, 1); }

	{ p->N_ITER_2_1		= Bitstream_Read(stream, 5); }

        for (uint32_t i = 0; i < p->N_ITER_2_1; ++i)
        {
            Axle_Load_Speed_Profile_Core_2_1_Decoder(stream, &(p->sub_2_1[i]));
        }


	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

