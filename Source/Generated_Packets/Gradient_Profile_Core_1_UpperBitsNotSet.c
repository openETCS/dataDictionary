
#include "Gradient_Profile_Core_1_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Gradient_Profile_Core_1_UpperBitsNotSet(const Gradient_Profile_Core_1* p)
{
    if (UpperBitsNotSet64(p->D_GRADIENT_k,      15)  &&
        UpperBitsNotSet64(p->Q_GDIR_k,          1)   &&
        UpperBitsNotSet64(p->G_A_k,             8))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

