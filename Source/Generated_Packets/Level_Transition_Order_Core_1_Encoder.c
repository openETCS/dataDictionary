
#include "Level_Transition_Order_Core_1_Encoder.h"
#include "Level_Transition_Order_Core_1_UpperBitsNotSet.h"
#include "Bitstream_Write.h"

int Level_Transition_Order_Core_1_Encoder(Bitstream* stream, const Level_Transition_Order_Core_1* p)
{
    if (NormalBitstream(stream, LEVEL_TRANSITION_ORDER_CORE_1_CORE_BITSIZE))
    {
        if (Level_Transition_Order_Core_1_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 3,  p->M_LEVELTR_k);
            if (p->M_LEVELTR_k == 1)
            {
            Bitstream_Write(stream, 8,  p->NID_NTC_k);
            }

            Bitstream_Write(stream, 15, p->L_ACKLEVELTR_k);



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

