
#include "Route_Suitability_Data_Decoder.h"
#include "Bitstream_Read.h"
#include "Route_Suitability_Data_Core_1_Decoder.h"

int Route_Suitability_Data_Decoder(Bitstream* stream, Route_Suitability_Data_Core* p)
{
    if (NormalBitstream(stream, ROUTE_SUITABILITY_DATA_CORE_BITSIZE))
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
	{ p->D_SUITABILITY		= Bitstream_Read(stream, 15); }

	{ p->Q_SUITABILITY		= Bitstream_Read(stream, 2); }

        if (p->Q_SUITABILITY == 0)
        {
	{ p->M_LINEGAUGE		= Bitstream_Read(stream, 8); }
        }

        if (p->Q_SUITABILITY == 1)
        {
	{ p->M_AXLELOADCAT		= Bitstream_Read(stream, 7); }
        }

        if (p->Q_SUITABILITY == 2)
        {
	{ p->M_VOLTAGE		= Bitstream_Read(stream, 4); }
        }

        if ((p->Q_SUITABILITY == 2) && (p->M_VOLTAGE != 0))
        {
	{ p->NID_CTRACTION		= Bitstream_Read(stream, 10); }
        }

	{ p->N_ITER_1		= Bitstream_Read(stream, 5); }

        for (uint32_t i = 0; i < p->N_ITER_1; ++i)
        {
            Route_Suitability_Data_Core_1_Decoder(stream, &(p->sub_1[i]));
        }        }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

