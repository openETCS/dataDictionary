
#include "Track_Condition_Station_Platforms_Core_1_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Track_Condition_Station_Platforms_Core_1_UpperBitsNotSet(const Track_Condition_Station_Platforms_Core_1* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->D_TRACKCOND_k,     15);
    status = status && UpperBitsNotSet64(p->L_TRACKCOND_k,     15);
    status = status && UpperBitsNotSet64(p->M_PLATFORM_k,      4) ;
    status = status && UpperBitsNotSet64(p->Q_PLATFORM_k,      2) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

