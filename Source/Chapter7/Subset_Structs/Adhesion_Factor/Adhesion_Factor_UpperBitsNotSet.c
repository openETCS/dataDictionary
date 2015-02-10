
#include "Adhesion_Factor_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Adhesion_Factor_UpperBitsNotSet(const Adhesion_Factor* p)
{
    if (UpperBitsNotSet64(p->data.Q_SCALE,           2)   &&
        UpperBitsNotSet64(p->data.D_ADHESION,        15)  &&
        UpperBitsNotSet64(p->data.L_ADHESION,        15)  &&
        UpperBitsNotSet64(p->data.M_ADHESION,        1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

