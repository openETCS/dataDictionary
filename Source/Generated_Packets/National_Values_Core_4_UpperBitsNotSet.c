
#include "National_Values_Core_4_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int National_Values_Core_4_UpperBitsNotSet(const National_Values_Core_4* p)
{
    if (UpperBitsNotSet64(p->L_NVKRINT_l,       5)   &&
        UpperBitsNotSet64(p->M_NVKRINT_l,       5))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

