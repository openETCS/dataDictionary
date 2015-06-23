
#include "Conditional_Level_Transition_Order_Encoder.h"
#include "Conditional_Level_Transition_Order_UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Conditional_Level_Transition_Order_Core_1_Encoder.h"

int Conditional_Level_Transition_Order_Encoder(Bitstream* stream, const Conditional_Level_Transition_Order_Core* p)
{
    if (NormalBitstream(stream, CONDITIONAL_LEVEL_TRANSITION_ORDER_CORE_BITSIZE))
    {
        if (Conditional_Level_Transition_Order_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 3,  p->M_LEVELTR);
            if (p->M_LEVELTR == 1)
            {
            Bitstream_Write(stream, 8,  p->NID_NTC);
            }

            Bitstream_Write(stream, 5,  p->N_ITER_1);
            for (uint32_t i = 0; i < p->N_ITER_1; ++i)
            {
                Conditional_Level_Transition_Order_Core_1_Encoder(stream, &(p->sub_1[i]));
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

