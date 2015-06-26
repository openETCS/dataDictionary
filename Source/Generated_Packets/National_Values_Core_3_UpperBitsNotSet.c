
#include "National_Values_Core_3_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int National_Values_Core_3_UpperBitsNotSet(const National_Values_Core_3* p)
{
    if (UpperBitsNotSet64(p->Q_NVKVINTSET_k,    2)   &&
        UpperBitsNotSet64(p->A_NVP12_k,         6)   &&
        UpperBitsNotSet64(p->A_NVP23_k,         6)   &&
        UpperBitsNotSet64(p->V_NVKVINT_k,       7)   &&
        UpperBitsNotSet64(p->M_NVKVINT_k,       7))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

