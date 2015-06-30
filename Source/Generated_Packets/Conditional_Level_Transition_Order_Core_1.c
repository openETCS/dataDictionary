
#include "Conditional_Level_Transition_Order_Core_1.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int Conditional_Level_Transition_Order_Core_1_UpperBitsNotSet(const Conditional_Level_Transition_Order_Core_1* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->M_LEVELTR_k,       3) ;
    if (p->M_LEVELTR_k == 1)
    {
    status = status && UpperBitsNotSet64(p->NID_NTC_k,         8) ;
    }

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Conditional_Level_Transition_Order_Core_1_Encoder(Bitstream* stream, const Conditional_Level_Transition_Order_Core_1* p)
{
    if (NormalBitstream(stream, CONDITIONAL_LEVEL_TRANSITION_ORDER_CORE_1_CORE_BITSIZE))
    {
        if (Conditional_Level_Transition_Order_Core_1_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 3,  p->M_LEVELTR_k);
            if (p->M_LEVELTR_k == 1)
            {
            Bitstream_Write(stream, 8,  p->NID_NTC_k);
            }




            return 1;
        }
        else
        {
            return -2;
        }
    }
    else
    {
        return -1;
    }
}

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

