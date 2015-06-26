
#include "Axle_Load_Speed_Profile_Core_2_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Axle_Load_Speed_Profile_Core_2_UpperBitsNotSet(const Axle_Load_Speed_Profile_Core_2* p)
{
    if (UpperBitsNotSet64(p->D_AXLELOAD_k,      15)  &&
        UpperBitsNotSet64(p->L_AXLELOAD_k,      15)  &&
        UpperBitsNotSet64(p->Q_FRONT_k,         1)   &&
        UpperBitsNotSet64(p->N_ITER_2_1,        5))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

