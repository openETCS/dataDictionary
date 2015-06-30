
#include "Temporary_Speed_Restriction_Core.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int Temporary_Speed_Restriction_UpperBitsNotSet(const Temporary_Speed_Restriction_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->NID_TSR,           8) ;
    status = status && UpperBitsNotSet64(p->D_TSR,             15);
    status = status && UpperBitsNotSet64(p->L_TSR,             15);
    status = status && UpperBitsNotSet64(p->Q_FRONT,           1) ;
    status = status && UpperBitsNotSet64(p->V_TSR,             7) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Temporary_Speed_Restriction_Encoder(Bitstream* stream, const Temporary_Speed_Restriction_Core* p)
{
    if (NormalBitstream(stream, TEMPORARY_SPEED_RESTRICTION_CORE_BITSIZE))
    {
        if (Temporary_Speed_Restriction_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 8,  p->NID_TSR);
            Bitstream_Write(stream, 15, p->D_TSR);
            Bitstream_Write(stream, 15, p->L_TSR);
            Bitstream_Write(stream, 1,  p->Q_FRONT);
            Bitstream_Write(stream, 7,  p->V_TSR);



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

int Temporary_Speed_Restriction_Decoder(Bitstream* stream, Temporary_Speed_Restriction_Core* p)
{
    if (NormalBitstream(stream, TEMPORARY_SPEED_RESTRICTION_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->Q_DIR		= Bitstream_Read(stream, 2); }

	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	{ p->Q_SCALE		= Bitstream_Read(stream, 2); }

	{ p->NID_TSR		= Bitstream_Read(stream, 8); }

	{ p->D_TSR		= Bitstream_Read(stream, 15); }

	{ p->L_TSR		= Bitstream_Read(stream, 15); }

	{ p->Q_FRONT		= Bitstream_Read(stream, 1); }

	{ p->V_TSR		= Bitstream_Read(stream, 7); }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

