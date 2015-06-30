
#include "Route_Suitability_Data_Core.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int Route_Suitability_Data_UpperBitsNotSet(const Route_Suitability_Data_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->Q_TRACKINIT,       1) ;
    if (p->Q_TRACKINIT == 1)
    {
    status = status && UpperBitsNotSet64(p->D_TRACKINIT,       15);
    }
    if (p->Q_TRACKINIT == 0)
    {
    status = status && UpperBitsNotSet64(p->D_SUITABILITY,     15);
    status = status && UpperBitsNotSet64(p->Q_SUITABILITY,     2) ;
    if (p->Q_SUITABILITY == 0)
    {
    status = status && UpperBitsNotSet64(p->M_LINEGAUGE,       8) ;
    }
    if (p->Q_SUITABILITY == 1)
    {
    status = status && UpperBitsNotSet64(p->M_AXLELOADCAT,     7) ;
    }
    if (p->Q_SUITABILITY == 2)
    {
    status = status && UpperBitsNotSet64(p->M_VOLTAGE,         4) ;
    }
    if ((p->Q_SUITABILITY == 2) && (p->M_VOLTAGE != 0))
    {
    status = status && UpperBitsNotSet64(p->NID_CTRACTION,     10);
    }
    status = status && UpperBitsNotSet64(p->N_ITER_1,          5) ;
    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        status = status && Route_Suitability_Data_Core_1_UpperBitsNotSet(&(p->sub_1[i]));
    }
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

int Route_Suitability_Data_Encoder(Bitstream* stream, const Route_Suitability_Data_Core* p)
{
    if (NormalBitstream(stream, ROUTE_SUITABILITY_DATA_CORE_BITSIZE))
    {
        if (Route_Suitability_Data_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 1,  p->Q_TRACKINIT);
            if (p->Q_TRACKINIT == 1)
            {
            Bitstream_Write(stream, 15, p->D_TRACKINIT);
            }

            if (p->Q_TRACKINIT == 0)
            {
            Bitstream_Write(stream, 15, p->D_SUITABILITY);
            Bitstream_Write(stream, 2,  p->Q_SUITABILITY);
            if (p->Q_SUITABILITY == 0)
            {
            Bitstream_Write(stream, 8,  p->M_LINEGAUGE);
            }

            if (p->Q_SUITABILITY == 1)
            {
            Bitstream_Write(stream, 7,  p->M_AXLELOADCAT);
            }

            if (p->Q_SUITABILITY == 2)
            {
            Bitstream_Write(stream, 4,  p->M_VOLTAGE);
            }

            if ((p->Q_SUITABILITY == 2) && (p->M_VOLTAGE != 0))
            {
            Bitstream_Write(stream, 10, p->NID_CTRACTION);
            }

            Bitstream_Write(stream, 5,  p->N_ITER_1);
            for (uint32_t i = 0; i < p->N_ITER_1; ++i)
            {
                Route_Suitability_Data_Core_1_Encoder(stream, &(p->sub_1[i]));
            }
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

