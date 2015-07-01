
#include "Conditional_Level_Transition_Order_Decoder.h"
#include "Bitstream_Read.h"
#include "Conditional_Level_Transition_Order_Core_1_Decoder.h"

int Conditional_Level_Transition_Order_Decoder(Bitstream* stream, Conditional_Level_Transition_Order_Core* p)
{
    if (NormalBitstream(stream, CONDITIONAL_LEVEL_TRANSITION_ORDER_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->Q_DIR		= Bitstream_Read(stream, 2); }

	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	{ p->M_LEVELTR		= Bitstream_Read(stream, 3); }

        if (p->M_LEVELTR == 1)
        {
	{ p->NID_NTC		= Bitstream_Read(stream, 8); }
        }

	{ p->N_ITER_1		= Bitstream_Read(stream, 5); }

        for (uint32_t i = 0; i < p->N_ITER_1; ++i)
        {
            Conditional_Level_Transition_Order_Core_1_Decoder(stream, &(p->sub_1[i]));
        }


	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

