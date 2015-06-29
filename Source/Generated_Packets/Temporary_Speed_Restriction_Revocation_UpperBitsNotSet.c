
#include "Temporary_Speed_Restriction_Revocation_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Temporary_Speed_Restriction_Revocation_UpperBitsNotSet(const Temporary_Speed_Restriction_Revocation_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->NID_TSR,           8) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

