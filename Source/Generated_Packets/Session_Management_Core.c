
#include "Session_Management_Core.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int Session_Management_UpperBitsNotSet(const Session_Management_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_RBC,             1) ;
    status = status && UpperBitsNotSet64(p->NID_C,             10);
    status = status && UpperBitsNotSet64(p->NID_RBC,           14);
    status = status && UpperBitsNotSet64(p->NID_RADIO,         64);
    status = status && UpperBitsNotSet64(p->Q_SLEEPSESSION,    1) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Session_Management_Encoder(Bitstream* stream, const Session_Management_Core* p)
{
    if (NormalBitstream(stream, SESSION_MANAGEMENT_CORE_BITSIZE))
    {
        if (Session_Management_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 1,  p->Q_RBC);
            Bitstream_Write(stream, 10, p->NID_C);
            Bitstream_Write(stream, 14, p->NID_RBC);
            Bitstream_Write(stream, 64, p->NID_RADIO);
            Bitstream_Write(stream, 1,  p->Q_SLEEPSESSION);



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

int Session_Management_Decoder(Bitstream* stream, Session_Management_Core* p)
{
    if (NormalBitstream(stream, SESSION_MANAGEMENT_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->Q_DIR		= Bitstream_Read(stream, 2); }

	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	{ p->Q_RBC		= Bitstream_Read(stream, 1); }

	{ p->NID_C		= Bitstream_Read(stream, 10); }

	{ p->NID_RBC		= Bitstream_Read(stream, 14); }

	{ p->NID_RADIO		= Bitstream_Read(stream, 64); }

	{ p->Q_SLEEPSESSION		= Bitstream_Read(stream, 1); }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

