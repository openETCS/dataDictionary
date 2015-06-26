
#include "Level_Transition_Order_Core_1_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Level_Transition_Order_Core_1_UpperBitsNotSet(const Level_Transition_Order_Core_1* p)
{
    if (UpperBitsNotSet64(p->M_LEVELTR_k,       3)   &&
        UpperBitsNotSet64(p->NID_NTC_k,         8)   &&
        UpperBitsNotSet64(p->L_ACKLEVELTR_k,    15))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

