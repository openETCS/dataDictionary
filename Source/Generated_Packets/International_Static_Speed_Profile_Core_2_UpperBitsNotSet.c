
#include "International_Static_Speed_Profile_Core_2_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int International_Static_Speed_Profile_Core_2_UpperBitsNotSet(const International_Static_Speed_Profile_Core_2* p)
{
    if (UpperBitsNotSet64(p->D_STATIC_k,        15)  &&
        UpperBitsNotSet64(p->V_STATIC_k,        7)   &&
        UpperBitsNotSet64(p->Q_FRONT_k,         1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

