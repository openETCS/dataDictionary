
#include "National_Values_Core_3_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"
#include "National_Values_Core_3_1_UpperBitsNotSet.h"

int National_Values_Core_3_UpperBitsNotSet(const National_Values_Core_3* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_NVKVINTSET_k,    2) ;
    if (p->Q_NVKVINTSET_k == 1)
    {
    status = status && UpperBitsNotSet64(p->A_NVP12_k,         6) ;
    status = status && UpperBitsNotSet64(p->A_NVP23_k,         6) ;
    }
    status = status && UpperBitsNotSet64(p->V_NVKVINT_k,       7) ;
    status = status && UpperBitsNotSet64(p->M_NVKVINT_k,       7) ;
    status = status && UpperBitsNotSet64(p->N_ITER_3_1,        5) ;
    for (uint32_t i = 0; i < p->N_ITER_3_1; ++i)
    {
        status = status && National_Values_Core_3_1_UpperBitsNotSet(&(p->sub_3_1[i]));
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

