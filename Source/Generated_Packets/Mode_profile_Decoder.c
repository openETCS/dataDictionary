
#include "Mode_profile_Decoder.h"
#include "Bitstream_Read.h"
#include "Mode_profile_Core_1_Decoder.h"

int Mode_profile_Decoder(Bitstream* stream, Mode_profile_Core* p)
{
    if (NormalBitstream(stream, MODE_PROFILE_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->Q_DIR		= Bitstream_Read(stream, 2); }

	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	{ p->Q_SCALE		= Bitstream_Read(stream, 2); }

	{ p->D_MAMODE		= Bitstream_Read(stream, 15); }

	{ p->M_MAMODE		= Bitstream_Read(stream, 2); }

	{ p->V_MAMODE		= Bitstream_Read(stream, 7); }

	{ p->L_MAMODE		= Bitstream_Read(stream, 15); }

	{ p->L_ACKMAMODE		= Bitstream_Read(stream, 15); }

	{ p->Q_MAMODE		= Bitstream_Read(stream, 1); }

	{ p->N_ITER_1		= Bitstream_Read(stream, 5); }

        for (uint32_t i = 0; i < p->N_ITER_1; ++i)
        {
            Mode_profile_Core_1_Decoder(stream, &(p->sub_1[i]));
        }


	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

