
#include "Danger_for_Shunting_information_Decoder.h"
#include "Bitstream_Read.h"

int Danger_for_Shunting_information_Decoder(Bitstream* stream, Danger_for_Shunting_information_Core* p)
{
    if (NormalBitstream(stream, DANGER_FOR_SHUNTING_INFORMATION_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->Q_DIR		= Bitstream_Read(stream, 2); }

	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	{ p->Q_ASPECT		= Bitstream_Read(stream, 1); }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

