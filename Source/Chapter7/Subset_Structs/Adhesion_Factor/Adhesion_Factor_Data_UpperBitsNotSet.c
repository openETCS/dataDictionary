
#include "Adhesion_Factor_Data_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Adhesion_Factor_Data_UpperBitsNotSet(const Adhesion_Factor_Data* p)
{
    if (UpperBitsNotSet64(p->Q_DIR,             2)   &&
        UpperBitsNotSet64(p->Q_SCALE,           2)   &&
        UpperBitsNotSet64(p->D_ADHESION,        15)  &&
        UpperBitsNotSet64(p->L_ADHESION,        15)  &&
        UpperBitsNotSet64(p->M_ADHESION,        1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

