
#include "International_Static_Speed_Profile_Core_2_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"
#include "International_Static_Speed_Profile_Core_2_1_UpperBitsNotSet.h"

int International_Static_Speed_Profile_Core_2_UpperBitsNotSet(const International_Static_Speed_Profile_Core_2* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->D_STATIC_k,        15);
    status = status && UpperBitsNotSet64(p->V_STATIC_k,        7) ;
    status = status && UpperBitsNotSet64(p->Q_FRONT_k,         1) ;
    status = status && UpperBitsNotSet64(p->N_ITER_2_1,        5) ;
    for (uint32_t i = 0; i < p->N_ITER_2_1; ++i)
    {
        status = status && International_Static_Speed_Profile_Core_2_1_UpperBitsNotSet(&(p->sub_2_1[i]));
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

