
#include "Session_Management_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Session_Management_UpperBitsNotSet(const Session_Management* p)
{
    if (UpperBitsNotSet64(p->NID_PACKET,        8)   &&
        UpperBitsNotSet64(p->Q_DIR,             2)   &&
        UpperBitsNotSet64(p->L_PACKET,          13)  &&
        UpperBitsNotSet64(p->Q_RBC,             1)   &&
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

