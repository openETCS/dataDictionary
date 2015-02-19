
#include "Reversing_area_information_Data_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Reversing_area_information_Data_UpperBitsNotSet(const Reversing_area_information_Data* p)
{
    if (UpperBitsNotSet64(p->Q_DIR,             2)   &&
        UpperBitsNotSet64(p->Q_SCALE,           2)   &&
        UpperBitsNotSet64(p->D_STARTREVERSE,    15)  &&
        UpperBitsNotSet64(p->L_REVERSEAREA,     15))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

