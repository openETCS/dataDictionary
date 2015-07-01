
#include "Conditional_Level_Transition_Order_Core_1_Decoder.h"
#include "Bitstream_Read.h"

int Conditional_Level_Transition_Order_Core_1_Decoder(Bitstream* stream, Conditional_Level_Transition_Order_Core_1* p)
{
    if (NormalBitstream(stream, CONDITIONAL_LEVEL_TRANSITION_ORDER_CORE_1_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->M_LEVELTR_k		= Bitstream_Read(stream, 3); }

        if (p->M_LEVELTR_k == 1)
        {
	{ p->NID_NTC_k		= Bitstream_Read(stream, 8); }
        }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

