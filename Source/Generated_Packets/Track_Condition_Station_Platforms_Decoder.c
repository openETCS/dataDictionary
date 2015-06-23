
#include "Track_Condition_Station_Platforms_Decoder.h"
#include "Bitstream_Read.h"
#include "Track_Condition_Station_Platforms_Core_1_Decoder.h"

int Track_Condition_Station_Platforms_Decoder(Bitstream* stream, Track_Condition_Station_Platforms_Core* p)
{
    if (NormalBitstream(stream, TRACK_CONDITION_STATION_PLATFORMS_CORE_BITSIZE))
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
	{ p->D_TRACKCOND		= Bitstream_Read(stream, 15); }

	{ p->L_TRACKCOND		= Bitstream_Read(stream, 15); }

	{ p->M_PLATFORM		= Bitstream_Read(stream, 4); }

	{ p->Q_PLATFORM		= Bitstream_Read(stream, 2); }

	{ p->N_ITER_1		= Bitstream_Read(stream, 5); }

        for (uint32_t i = 0; i < p->N_ITER_1; ++i)
        {
            Track_Condition_Station_Platforms_Core_1_Decoder(stream, &(p->sub_1[i]));
        }        }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

