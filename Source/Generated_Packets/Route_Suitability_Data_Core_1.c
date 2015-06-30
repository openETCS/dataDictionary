
#include "Route_Suitability_Data_Core_1.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int Route_Suitability_Data_Core_1_UpperBitsNotSet(const Route_Suitability_Data_Core_1* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->D_SUITABILITY_k,   15);
    status = status && UpperBitsNotSet64(p->Q_SUITABILITY_k,   2) ;
    if (p->Q_SUITABILITY_k == 0)
    {
    status = status && UpperBitsNotSet64(p->M_LINEGAUGE_k,     8) ;
    }
    if (p->Q_SUITABILITY_k == 1)
    {
    status = status && UpperBitsNotSet64(p->M_AXLELOADCAT_k,   7) ;
    }
    if (p->Q_SUITABILITY_k == 2)
    {
    status = status && UpperBitsNotSet64(p->M_VOLTAGE_k,       4) ;
    }
    if ((p->Q_SUITABILITY_k == 2) && (p->M_VOLTAGE_k != 0))
    {
    status = status && UpperBitsNotSet64(p->NID_CTRACTION_k,   10);
    }

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Route_Suitability_Data_Core_1_Encoder(Bitstream* stream, const Route_Suitability_Data_Core_1* p)
{
    if (NormalBitstream(stream, ROUTE_SUITABILITY_DATA_CORE_1_CORE_BITSIZE))
    {
        if (Route_Suitability_Data_Core_1_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 15, p->D_SUITABILITY_k);
            Bitstream_Write(stream, 2,  p->Q_SUITABILITY_k);
            if (p->Q_SUITABILITY_k == 0)
            {
            Bitstream_Write(stream, 8,  p->M_LINEGAUGE_k);
            }

            if (p->Q_SUITABILITY_k == 1)
            {
            Bitstream_Write(stream, 7,  p->M_AXLELOADCAT_k);
            }

            if (p->Q_SUITABILITY_k == 2)
            {
            Bitstream_Write(stream, 4,  p->M_VOLTAGE_k);
            }

            if ((p->Q_SUITABILITY_k == 2) && (p->M_VOLTAGE_k != 0))
            {
            Bitstream_Write(stream, 10, p->NID_CTRACTION_k);
            }




            return 1;
        }
        else
        {
            return -2;
        }
    }
    else
    {
        return -1;
    }
}

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

