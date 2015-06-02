
#include "RBC_transition_order_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int RBC_transition_order_UpperBitsNotSet(const RBC_transition_order_Core* p)
{
    if (UpperBitsNotSet64(p->Q_DIR,             2)   &&
        UpperBitsNotSet64(p->L_PACKET,          13)  &&
        UpperBitsNotSet64(p->Q_SCALE,           2)   &&
        UpperBitsNotSet64(p->D_RBCTR,           15)  &&
        UpperBitsNotSet64(p->NID_C,             10)  &&
        UpperBitsNotSet64(p->NID_RBC,           14)  &&
        UpperBitsNotSet64(p->NID_RADIO,         64)  &&
        UpperBitsNotSet64(p->Q_SLEEPSESSION,    1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

