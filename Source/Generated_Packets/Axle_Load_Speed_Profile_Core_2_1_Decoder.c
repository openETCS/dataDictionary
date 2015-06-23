
#include "Axle_Load_Speed_Profile_Core_2_1_Decoder.h"
#include "Bitstream_Read.h"

int Axle_Load_Speed_Profile_Core_2_1_Decoder(Bitstream* stream, Axle_Load_Speed_Profile_Core_2_1* p)
{
    if (NormalBitstream(stream, AXLE_LOAD_SPEED_PROFILE_CORE_2_1_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->M_AXLELOADCAT_k_m		= Bitstream_Read(stream, 7); }

	{ p->V_AXLELOAD_k_m		= Bitstream_Read(stream, 7); }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

