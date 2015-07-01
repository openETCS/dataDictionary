
#include "Virtual_Balise_Cover_order_Decoder.h"
#include "Bitstream_Read.h"

int Virtual_Balise_Cover_order_Decoder(Bitstream* stream, Virtual_Balise_Cover_order_Core* p)
{
    if (NormalBitstream(stream, VIRTUAL_BALISE_COVER_ORDER_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->Q_DIR		= Bitstream_Read(stream, 2); }

	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	{ p->Q_VBCO		= Bitstream_Read(stream, 1); }

	{ p->NID_VBCMK		= Bitstream_Read(stream, 6); }

	{ p->NID_C		= Bitstream_Read(stream, 10); }

        if (p->Q_VBCO == 1)
        {
	{ p->T_VBC		= Bitstream_Read(stream, 8); }
        }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

