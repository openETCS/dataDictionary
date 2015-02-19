
#include "Reversing_supervision_information_Data_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Reversing_supervision_information_Data_UpperBitsNotSet(const Reversing_supervision_information_Data* p)
{
    if (UpperBitsNotSet64(p->Q_DIR,             2)   &&
        UpperBitsNotSet64(p->Q_SCALE,           2)   &&
        UpperBitsNotSet64(p->D_REVERSE,         15)  &&
        UpperBitsNotSet64(p->V_REVERSE,         7))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

