
#include "National_Values_Core_1_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int National_Values_Core_1_UpperBitsNotSet(const National_Values_Core_1* p)
{
    if (UpperBitsNotSet64(p->NID_C_p,           10))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

