
#include "Temporary_Speed_Restriction_Decoder.h"
#include "Bitstream_Read.h"

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

