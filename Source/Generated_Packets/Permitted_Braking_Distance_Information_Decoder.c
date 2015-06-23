
#include "Permitted_Braking_Distance_Information_Decoder.h"
#include "Bitstream_Read.h"
#include "Permitted_Braking_Distance_Information_Core_1_Decoder.h"

int Permitted_Braking_Distance_Information_Decoder(Bitstream* stream, Permitted_Braking_Distance_Information_Core* p)
{
    if (NormalBitstream(stream, PERMITTED_BRAKING_DISTANCE_INFORMATION_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->Q_DIR		= Bitstream_Read(stream, 2); }

	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	{ p->Q_SCALE		= Bitstream_Read(stream, 2); }

	{ p->Q_TRACKINIT		= Bitstream_Read(stream, 1); }

        if (p->Q_TRACKINIT == 1)
        {
	{ p->D_TRACKINIT		= Bitstream_Read(stream, 15); }
        }

        if (p->Q_TRACKINIT == 0)
        {
	{ p->D_PBD		= Bitstream_Read(stream, 15); }

	{ p->Q_GDIR		= Bitstream_Read(stream, 1); }

	{ p->G_PBDSR		= Bitstream_Read(stream, 8); }

	{ p->Q_PBDSR		= Bitstream_Read(stream, 1); }

	{ p->D_PBDSR		= Bitstream_Read(stream, 15); }

	{ p->L_PBDSR		= Bitstream_Read(stream, 15); }

	{ p->N_ITER_1		= Bitstream_Read(stream, 5); }

        for (uint32_t i = 0; i < p->N_ITER_1; ++i)
        {
            Permitted_Braking_Distance_Information_Core_1_Decoder(stream, &(p->sub_1[i]));
        }        }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

