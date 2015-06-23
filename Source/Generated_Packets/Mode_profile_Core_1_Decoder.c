
#include "Mode_profile_Core_1_Decoder.h"
#include "Bitstream_Read.h"

int Mode_profile_Core_1_Decoder(Bitstream* stream, Mode_profile_Core_1* p)
{
    if (NormalBitstream(stream, MODE_PROFILE_CORE_1_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->D_MAMODE_k		= Bitstream_Read(stream, 15); }

	{ p->M_MAMODE_k		= Bitstream_Read(stream, 2); }

	{ p->V_MAMODE_k		= Bitstream_Read(stream, 7); }

	{ p->L_MAMODE_k		= Bitstream_Read(stream, 15); }

	{ p->L_ACKMAMODE_k		= Bitstream_Read(stream, 15); }

	{ p->Q_MAMODE_k		= Bitstream_Read(stream, 1); }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

