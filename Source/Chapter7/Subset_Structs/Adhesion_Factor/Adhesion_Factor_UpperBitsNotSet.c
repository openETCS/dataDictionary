
#include "Adhesion_Factor_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Adhesion_Factor_UpperBitsNotSet(const Adhesion_Factor* p)
{
    if (UpperBitsNotSet64(p->Header.NID_PACKET,        8)   &&
        UpperBitsNotSet64(p->Header.Q_DIR,             2)   &&
        UpperBitsNotSet64(p->Header.L_PACKET,          13)  &&
        UpperBitsNotSet64(p->Data.Q_SCALE,           2)   &&
        UpperBitsNotSet64(p->Data.D_ADHESION,        15)  &&
        UpperBitsNotSet64(p->Data.L_ADHESION,        15)  &&
        UpperBitsNotSet64(p->Data.M_ADHESION,        1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

