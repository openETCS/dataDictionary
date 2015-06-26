
#include "National_Values_Core_2_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int National_Values_Core_2_UpperBitsNotSet(const National_Values_Core_2* p)
{
    if (UpperBitsNotSet64(p->V_NVKVINT_n,       7)   &&
        UpperBitsNotSet64(p->M_NVKVINT_n,       7))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

