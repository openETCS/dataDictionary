
#include "Temporary_Speed_Restriction_Revocation_Decoder.h"
#include "Bitstream_Read.h"

int Temporary_Speed_Restriction_Revocation_Decoder(Bitstream* stream, Temporary_Speed_Restriction_Revocation_Core* p)
{
    if (NormalBitstream(stream, TEMPORARY_SPEED_RESTRICTION_REVOCATION_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->Q_DIR		= Bitstream_Read(stream, 2); }

	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	{ p->NID_TSR		= Bitstream_Read(stream, 8); }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

