
#include "Stop_if_in_Staff_Responsible_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Stop_if_in_Staff_Responsible_UpperBitsNotSet(const Stop_if_in_Staff_Responsible* p)
{
    if (UpperBitsNotSet64(p->NID_PACKET,        8)   &&
        UpperBitsNotSet64(p->Q_DIR,             2)   &&
        UpperBitsNotSet64(p->L_PACKET,          13)  &&
        UpperBitsNotSet64(p->Q_SRSTOP,          1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

