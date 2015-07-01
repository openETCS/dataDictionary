
#include "Radio_Network_registration_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Radio_Network_registration_UpperBitsNotSet(const Radio_Network_registration_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->NID_MN,            24);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

