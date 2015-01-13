
#include "Track_Condition_Big_Metal_Masses_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Track_Condition_Big_Metal_Masses_UpperBitsNotSet(const Track_Condition_Big_Metal_Masses* p)
{
    if (UpperBitsNotSet64(p->NID_PACKET,        8)   &&
        UpperBitsNotSet64(p->Q_DIR,             2)   &&
        UpperBitsNotSet64(p->L_PACKET,          13)  &&
        UpperBitsNotSet64(p->Q_SCALE,           2)   &&
        UpperBitsNotSet64(p->D_TRACKCOND,       15)  &&
        UpperBitsNotSet64(p->L_TRACKCOND,       15)  &&
        UpperBitsNotSet64(p->N_ITER,            5)   &&
        UpperBitsNotSet64(p->D_TRACKCOND(k),    15)  &&
        UpperBitsNotSet64(p->L_TRACKCOND(k),    15))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

