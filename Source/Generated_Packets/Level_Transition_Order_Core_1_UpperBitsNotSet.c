
#include "Level_Transition_Order_Core_1_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Level_Transition_Order_Core_1_UpperBitsNotSet(const Level_Transition_Order_Core_1* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->M_LEVELTR_k,       3) ;
    if (p->M_LEVELTR_k == 1)
    {
    status = status && UpperBitsNotSet64(p->NID_NTC_k,         8) ;
    }
    status = status && UpperBitsNotSet64(p->L_ACKLEVELTR_k,    15);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

