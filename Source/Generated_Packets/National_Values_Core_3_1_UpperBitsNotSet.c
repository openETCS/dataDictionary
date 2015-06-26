
#include "National_Values_Core_3_1_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int National_Values_Core_3_1_UpperBitsNotSet(const National_Values_Core_3_1* p)
{
    if (UpperBitsNotSet64(p->V_NVKVINT_k_m,     7)   &&
        UpperBitsNotSet64(p->M_NVKVINT_k_m,     7))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

