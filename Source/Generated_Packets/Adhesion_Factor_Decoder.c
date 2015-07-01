
#include "Adhesion_Factor_Decoder.h"
#include "Bitstream_Read.h"

int Adhesion_Factor_Decoder(Bitstream* stream, Adhesion_Factor_Core* p)
{
    if (NormalBitstream(stream, ADHESION_FACTOR_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->Q_DIR		= Bitstream_Read(stream, 2); }

	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	{ p->Q_SCALE		= Bitstream_Read(stream, 2); }

	{ p->D_ADHESION		= Bitstream_Read(stream, 15); }

	{ p->L_ADHESION		= Bitstream_Read(stream, 15); }

	{ p->M_ADHESION		= Bitstream_Read(stream, 1); }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

