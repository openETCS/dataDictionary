
#include "Temporary_Speed_Restriction_Revocation_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Temporary_Speed_Restriction_Revocation_UpperBitsNotSet(const Temporary_Speed_Restriction_Revocation* p)
{
    if (UpperBitsNotSet64(p->NID_PACKET,        8)   &&
        UpperBitsNotSet64(p->Q_DIR,             2)   &&
        UpperBitsNotSet64(p->L_PACKET,          13)  &&
        UpperBitsNotSet64(p->NID_TSR,           8))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

