
#include "Axle_Load_Speed_Profile_Core_2_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"
#include "Axle_Load_Speed_Profile_Core_2_1_UpperBitsNotSet.h"

int Axle_Load_Speed_Profile_Core_2_UpperBitsNotSet(const Axle_Load_Speed_Profile_Core_2* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->D_AXLELOAD_k,      15);
    status = status && UpperBitsNotSet64(p->L_AXLELOAD_k,      15);
    status = status && UpperBitsNotSet64(p->Q_FRONT_k,         1) ;
    status = status && UpperBitsNotSet64(p->N_ITER_2_1,        5) ;
    for (uint32_t i = 0; i < p->N_ITER_2_1; ++i)
    {
        status = status && Axle_Load_Speed_Profile_Core_2_1_UpperBitsNotSet(&(p->sub_2_1[i]));
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

