
#include "Conditional_Level_Transition_Order_Core_1_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

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

