
#include "Mode_profile_Core_1_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Mode_profile_Core_1_UpperBitsNotSet(const Mode_profile_Core_1* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->D_MAMODE_k,        15);
    status = status && UpperBitsNotSet64(p->M_MAMODE_k,        2) ;
    status = status && UpperBitsNotSet64(p->V_MAMODE_k,        7) ;
    status = status && UpperBitsNotSet64(p->L_MAMODE_k,        15);
    status = status && UpperBitsNotSet64(p->L_ACKMAMODE_k,     15);
    status = status && UpperBitsNotSet64(p->Q_MAMODE_k,        1) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

