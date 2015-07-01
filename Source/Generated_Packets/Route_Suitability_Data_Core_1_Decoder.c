
#include "Route_Suitability_Data_Core_1_Decoder.h"
#include "Bitstream_Read.h"

int Route_Suitability_Data_Core_1_Decoder(Bitstream* stream, Route_Suitability_Data_Core_1* p)
{
    if (NormalBitstream(stream, ROUTE_SUITABILITY_DATA_CORE_1_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->D_SUITABILITY_k		= Bitstream_Read(stream, 15); }

	{ p->Q_SUITABILITY_k		= Bitstream_Read(stream, 2); }

        if (p->Q_SUITABILITY_k == 0)
        {
	{ p->M_LINEGAUGE_k		= Bitstream_Read(stream, 8); }
        }

        if (p->Q_SUITABILITY_k == 1)
        {
	{ p->M_AXLELOADCAT_k		= Bitstream_Read(stream, 7); }
        }

        if (p->Q_SUITABILITY_k == 2)
        {
	{ p->M_VOLTAGE_k		= Bitstream_Read(stream, 4); }
        }

        if ((p->Q_SUITABILITY_k == 2) && (p->M_VOLTAGE_k != 0))
        {
	{ p->NID_CTRACTION_k		= Bitstream_Read(stream, 10); }
        }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

