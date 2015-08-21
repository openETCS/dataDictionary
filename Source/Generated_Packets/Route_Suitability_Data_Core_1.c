
#include "Route_Suitability_Data_Core_1.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"
#include "Bitstream_Normal.h"

int Route_Suitability_Data_Core_1_UpperBitsNotSet(const Route_Suitability_Data_Core_1* p)
{
    bool status = true;

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
    if (Bitstream_Normal(stream, ROUTE_SUITABILITY_DATA_CORE_1_CORE_BITSIZE))
    {
        if (Route_Suitability_Data_Core_1_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

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



            //@ assert D_SUITABILITY:     EqualBits(stream, pos,       pos + 15,  p->D_SUITABILITY);
            //@ assert Q_SUITABILITY:     EqualBits(stream, pos + 15,  pos + 17,  p->Q_SUITABILITY);

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
    if (Bitstream_Normal(stream, ROUTE_SUITABILITY_DATA_CORE_1_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	/*@
	  requires D_SUITABILITY:  stream->bitpos == pos + 0;
	  assigns        	   stream->bitpos;
	  assigns		   p->D_SUITABILITY;
	  ensures  D_SUITABILITY:  stream->bitpos == pos + 15;
	  ensures  D_SUITABILITY:  EqualBits(stream, pos + 0, pos + 15, p->D_SUITABILITY);
	  ensures  D_SUITABILITY:  UpperBitsNotSet(p->D_SUITABILITY, 15);
	*/
	{ p->D_SUITABILITY		= Bitstream_Read(stream, 15); }

	/*@
	  requires Q_SUITABILITY:  stream->bitpos == pos + 15;
	  assigns        	   stream->bitpos;
	  assigns		   p->Q_SUITABILITY;
	  ensures  Q_SUITABILITY:  stream->bitpos == pos + 17;
	  ensures  Q_SUITABILITY:  EqualBits(stream, pos + 15, pos + 17, p->Q_SUITABILITY);
	  ensures  Q_SUITABILITY:  UpperBitsNotSet(p->Q_SUITABILITY, 2);
	*/
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

        //@ assert D_SUITABILITY:     EqualBits(stream, pos,       pos + 15,  p->D_SUITABILITY);
        //@ assert Q_SUITABILITY:     EqualBits(stream, pos + 15,  pos + 17,  p->Q_SUITABILITY);

        //@ assert D_SUITABILITY:     UpperBitsNotSet(p->D_SUITABILITY,     15);
        //@ assert Q_SUITABILITY:     UpperBitsNotSet(p->Q_SUITABILITY,     2);

	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

