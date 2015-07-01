
#include "National_Values_Core_4_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int National_Values_Core_4_UpperBitsNotSet(const National_Values_Core_4* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->L_NVKRINT_l,       5) ;
    status = status && UpperBitsNotSet64(p->M_NVKRINT_l,       5) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

