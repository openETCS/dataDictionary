
#include "Level_Transition_Order_Decoder.h"
#include "Bitstream_Read.h"
#include "Level_Transition_Order_Core_1_Decoder.h"

int Level_Transition_Order_Decoder(Bitstream* stream, Level_Transition_Order_Core* p)
{
    if (NormalBitstream(stream, LEVEL_TRANSITION_ORDER_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->Q_DIR		= Bitstream_Read(stream, 2); }

	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	{ p->Q_SCALE		= Bitstream_Read(stream, 2); }

	{ p->D_LEVELTR		= Bitstream_Read(stream, 15); }

	{ p->M_LEVELTR		= Bitstream_Read(stream, 3); }

        if (p->M_LEVELTR == 1)
        {
	{ p->NID_NTC		= Bitstream_Read(stream, 8); }
        }

	{ p->L_ACKLEVELTR		= Bitstream_Read(stream, 15); }

	{ p->N_ITER_1		= Bitstream_Read(stream, 5); }

        for (uint32_t i = 0; i < p->N_ITER_1; ++i)
        {
            Level_Transition_Order_Core_1_Decoder(stream, &(p->sub_1[i]));
        }


	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

