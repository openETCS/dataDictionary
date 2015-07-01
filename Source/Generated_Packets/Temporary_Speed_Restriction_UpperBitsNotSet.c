
#include "Temporary_Speed_Restriction_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Temporary_Speed_Restriction_UpperBitsNotSet(const Temporary_Speed_Restriction_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->NID_TSR,           8) ;
    status = status && UpperBitsNotSet64(p->D_TSR,             15);
    status = status && UpperBitsNotSet64(p->L_TSR,             15);
    status = status && UpperBitsNotSet64(p->Q_FRONT,           1) ;
    status = status && UpperBitsNotSet64(p->V_TSR,             7) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

