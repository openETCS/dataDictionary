
#include "Infill_location_reference_Core.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int Infill_location_reference_UpperBitsNotSet(const Infill_location_reference_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_NEWCOUNTRY,      1) ;
    if (p->Q_NEWCOUNTRY == 1)
    {
    status = status && UpperBitsNotSet64(p->NID_C,             10);
    }
    status = status && UpperBitsNotSet64(p->NID_BG,            14);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Infill_location_reference_Encoder(Bitstream* stream, const Infill_location_reference_Core* p)
{
    if (NormalBitstream(stream, INFILL_LOCATION_REFERENCE_CORE_BITSIZE))
    {
        if (Infill_location_reference_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 1,  p->Q_NEWCOUNTRY);
            if (p->Q_NEWCOUNTRY == 1)
            {
            Bitstream_Write(stream, 10, p->NID_C);
            }

            Bitstream_Write(stream, 14, p->NID_BG);



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

int Infill_location_reference_Decoder(Bitstream* stream, Infill_location_reference_Core* p)
{
    if (NormalBitstream(stream, INFILL_LOCATION_REFERENCE_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->Q_DIR		= Bitstream_Read(stream, 2); }

	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	{ p->Q_NEWCOUNTRY		= Bitstream_Read(stream, 1); }

        if (p->Q_NEWCOUNTRY == 1)
        {
	{ p->NID_C		= Bitstream_Read(stream, 10); }
        }

	{ p->NID_BG		= Bitstream_Read(stream, 14); }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

