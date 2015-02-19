
#include "Temporary_Speed_Restriction_Revocation_Data_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Temporary_Speed_Restriction_Revocation_Data_UpperBitsNotSet(const Temporary_Speed_Restriction_Revocation_Data* p)
{
    if (UpperBitsNotSet64(p->Q_DIR,             2)   &&
        UpperBitsNotSet64(p->NID_TSR,           8))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

