
#include "Conditional_Level_Transition_Order_Core_1_Encoder.h"
#include "Conditional_Level_Transition_Order_Core_1_UpperBitsNotSet.h"
#include "Bitstream_Write.h"

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

