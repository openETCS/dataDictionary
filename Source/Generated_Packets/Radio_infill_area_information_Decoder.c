
#include "Radio_infill_area_information_Decoder.h"
#include "Bitstream_Read.h"

int Radio_infill_area_information_Decoder(Bitstream* stream, Radio_infill_area_information_Core* p)
{
    if (NormalBitstream(stream, RADIO_INFILL_AREA_INFORMATION_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->Q_DIR		= Bitstream_Read(stream, 2); }

	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	{ p->Q_SCALE		= Bitstream_Read(stream, 2); }

	{ p->Q_RIU		= Bitstream_Read(stream, 1); }

	{ p->NID_C		= Bitstream_Read(stream, 10); }

	{ p->NID_RIU		= Bitstream_Read(stream, 14); }

	{ p->NID_RADIO		= Bitstream_Read(stream, 64); }

	{ p->D_INFILL		= Bitstream_Read(stream, 15); }

	{ p->NID_BG		= Bitstream_Read(stream, 14); }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

