
#include "Default_Gradient_for_Temporary_Speed_Restriction_Data_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Default_Gradient_for_Temporary_Speed_Restriction_Data_UpperBitsNotSet(const Default_Gradient_for_Temporary_Speed_Restriction_Data* p)
{
    if (UpperBitsNotSet64(p->Q_DIR,             2)   &&
        UpperBitsNotSet64(p->Q_GDIR,            1)   &&
        UpperBitsNotSet64(p->G_TSR,             8))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

