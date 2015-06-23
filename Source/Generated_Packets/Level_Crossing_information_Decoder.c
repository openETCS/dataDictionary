
#include "Level_Crossing_information_Decoder.h"
#include "Bitstream_Read.h"

int Level_Crossing_information_Decoder(Bitstream* stream, Level_Crossing_information_Core* p)
{
    if (NormalBitstream(stream, LEVEL_CROSSING_INFORMATION_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->Q_DIR		= Bitstream_Read(stream, 2); }

	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	{ p->Q_SCALE		= Bitstream_Read(stream, 2); }

	{ p->NID_LX		= Bitstream_Read(stream, 8); }

	{ p->D_LX		= Bitstream_Read(stream, 15); }

	{ p->L_LX		= Bitstream_Read(stream, 15); }

	{ p->Q_LXSTATUS		= Bitstream_Read(stream, 1); }

        if (p->Q_LXSTATUS == 1)
        {
	{ p->V_LX		= Bitstream_Read(stream, 7); }

	{ p->Q_STOPLX		= Bitstream_Read(stream, 1); }
        }

        if (p->Q_STOPLX == 1)
        {
	{ p->L_STOPLX		= Bitstream_Read(stream, 15); }
        }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

