
#include "Track_Condition_Station_Platforms_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"
#include "Track_Condition_Station_Platforms_Core_1_UpperBitsNotSet.h"

int Track_Condition_Station_Platforms_UpperBitsNotSet(const Track_Condition_Station_Platforms_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->Q_TRACKINIT,       1) ;
    if (p->Q_TRACKINIT == 1)
    {
    status = status && UpperBitsNotSet64(p->D_TRACKINIT,       15);
    }
    if (p->Q_TRACKINIT == 0)
    {
    status = status && UpperBitsNotSet64(p->D_TRACKCOND,       15);
    status = status && UpperBitsNotSet64(p->L_TRACKCOND,       15);
    status = status && UpperBitsNotSet64(p->M_PLATFORM,        4) ;
    status = status && UpperBitsNotSet64(p->Q_PLATFORM,        2) ;
    status = status && UpperBitsNotSet64(p->N_ITER_1,          5) ;
    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        status = status && Track_Condition_Station_Platforms_Core_1_UpperBitsNotSet(&(p->sub_1[i]));
    }
    }

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

