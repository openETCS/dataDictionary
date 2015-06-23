
#include "Reversing_area_information_Decoder.h"
#include "Bitstream_Read.h"

int Reversing_area_information_Decoder(Bitstream* stream, Reversing_area_information_Core* p)
{
    if (NormalBitstream(stream, REVERSING_AREA_INFORMATION_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->Q_DIR		= Bitstream_Read(stream, 2); }

	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	{ p->Q_SCALE		= Bitstream_Read(stream, 2); }

	{ p->D_STARTREVERSE		= Bitstream_Read(stream, 15); }

	{ p->L_REVERSEAREA		= Bitstream_Read(stream, 15); }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

