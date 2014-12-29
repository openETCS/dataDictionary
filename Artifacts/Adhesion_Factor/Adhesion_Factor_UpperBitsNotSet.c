
#include "Adhesion_Factor_UpperBitsNotSet.h"
#include "Bit64.h"

int Adhesion_Factor_UpperBitsNotSet(const Adhesion_Factor* p)
{
    if (UpperBitsNotSet64(p->ABC, 8) &&
        UpperBitsNotSet64(p->DEF, 3) &&
        UpperBitsNotSet64(p->GHI, 17))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

