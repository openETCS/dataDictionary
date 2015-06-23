
#include "Track_Condition_Big_Metal_Masses_Decoder.h"
#include "Bitstream_Read.h"
#include "Track_Condition_Big_Metal_Masses_Core_1_Decoder.h"

int Track_Condition_Big_Metal_Masses_Decoder(Bitstream* stream, Track_Condition_Big_Metal_Masses_Core* p)
{
    if (NormalBitstream(stream, TRACK_CONDITION_BIG_METAL_MASSES_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->Q_DIR		= Bitstream_Read(stream, 2); }

	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	{ p->Q_SCALE		= Bitstream_Read(stream, 2); }

	{ p->D_TRACKCOND		= Bitstream_Read(stream, 15); }

	{ p->L_TRACKCOND		= Bitstream_Read(stream, 15); }

	{ p->N_ITER_1		= Bitstream_Read(stream, 5); }

        for (uint32_t i = 0; i < p->N_ITER_1; ++i)
        {
            Track_Condition_Big_Metal_Masses_Core_1_Decoder(stream, &(p->sub_1[i]));
        }


	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

