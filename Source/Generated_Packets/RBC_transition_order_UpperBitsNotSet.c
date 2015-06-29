
#include "RBC_transition_order_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int RBC_transition_order_UpperBitsNotSet(const RBC_transition_order_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->D_RBCTR,           15);
    status = status && UpperBitsNotSet64(p->NID_C,             10);
    status = status && UpperBitsNotSet64(p->NID_RBC,           14);
    status = status && UpperBitsNotSet64(p->NID_RADIO,         64);
    status = status && UpperBitsNotSet64(p->Q_SLEEPSESSION,    1) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

