
#include "Track_Condition_Big_Metal_Masses_Core_1_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Track_Condition_Big_Metal_Masses_Core_1_UpperBitsNotSet(const Track_Condition_Big_Metal_Masses_Core_1* p)
{
    if (UpperBitsNotSet64(p->D_TRACKCOND_k,     15)  &&
        UpperBitsNotSet64(p->L_TRACKCOND_k,     15))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

