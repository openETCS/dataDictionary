
#include "Stop_if_in_Staff_Responsible_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Stop_if_in_Staff_Responsible_UpperBitsNotSet(const Stop_if_in_Staff_Responsible_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SRSTOP,          1) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

