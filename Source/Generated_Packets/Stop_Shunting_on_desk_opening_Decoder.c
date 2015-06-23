
#include "Stop_Shunting_on_desk_opening_Decoder.h"
#include "Bitstream_Read.h"

int Stop_Shunting_on_desk_opening_Decoder(Bitstream* stream, Stop_Shunting_on_desk_opening_Core* p)
{
    if (NormalBitstream(stream, STOP_SHUNTING_ON_DESK_OPENING_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->Q_DIR		= Bitstream_Read(stream, 2); }

	{ p->L_PACKET		= Bitstream_Read(stream, 13); }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

