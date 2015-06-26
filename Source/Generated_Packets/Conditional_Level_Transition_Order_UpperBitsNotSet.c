
#include "Conditional_Level_Transition_Order_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Conditional_Level_Transition_Order_UpperBitsNotSet(const Conditional_Level_Transition_Order_Core* p)
{
    if (UpperBitsNotSet64(p->Q_DIR,             2)   &&
        UpperBitsNotSet64(p->L_PACKET,          13)  &&
        UpperBitsNotSet64(p->M_LEVELTR,         3)   &&
        UpperBitsNotSet64(p->NID_NTC,           8)   &&
        UpperBitsNotSet64(p->N_ITER_1,          5))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

