
#include "Conditional_Level_Transition_Order_Core_1_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Conditional_Level_Transition_Order_Core_1_UpperBitsNotSet(const Conditional_Level_Transition_Order_Core_1* p)
{
    if (UpperBitsNotSet64(p->M_LEVELTR_k,       3)   &&
        UpperBitsNotSet64(p->NID_NTC_k,         8))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

