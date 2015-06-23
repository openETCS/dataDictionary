
#include "RBC_transition_order_Decoder.h"
#include "Bitstream_Read.h"

int RBC_transition_order_Decoder(Bitstream* stream, RBC_transition_order_Core* p)
{
    if (NormalBitstream(stream, RBC_TRANSITION_ORDER_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->Q_DIR		= Bitstream_Read(stream, 2); }

	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	{ p->Q_SCALE		= Bitstream_Read(stream, 2); }

	{ p->D_RBCTR		= Bitstream_Read(stream, 15); }

	{ p->NID_C		= Bitstream_Read(stream, 10); }

	{ p->NID_RBC		= Bitstream_Read(stream, 14); }

	{ p->NID_RADIO		= Bitstream_Read(stream, 64); }

	{ p->Q_SLEEPSESSION		= Bitstream_Read(stream, 1); }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

