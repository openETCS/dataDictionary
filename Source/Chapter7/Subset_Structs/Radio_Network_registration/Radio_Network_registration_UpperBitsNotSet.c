
#include "Radio_Network_registration_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Radio_Network_registration_UpperBitsNotSet(const Radio_Network_registration* p)
{
    if (UpperBitsNotSet64(p->NID_PACKET,        8)   &&
        UpperBitsNotSet64(p->Q_DIR,             2)   &&
        UpperBitsNotSet64(p->L_PACKET,          13)  &&
        UpperBitsNotSet64(p->NID_MN,            24))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

