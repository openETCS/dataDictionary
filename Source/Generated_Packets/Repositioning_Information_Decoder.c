
#include "Repositioning_Information_Decoder.h"
#include "Bitstream_Read.h"

int Repositioning_Information_Decoder(Bitstream* stream, Repositioning_Information_Core* p)
{
    if (NormalBitstream(stream, REPOSITIONING_INFORMATION_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->Q_DIR		= Bitstream_Read(stream, 2); }

	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	{ p->Q_SCALE		= Bitstream_Read(stream, 2); }

	{ p->L_SECTION		= Bitstream_Read(stream, 15); }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

