
#include "Track_Condition_Station_Platforms_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Track_Condition_Station_Platforms_UpperBitsNotSet(const Track_Condition_Station_Platforms_Core* p)
{
    if (UpperBitsNotSet64(p->Q_DIR,             2)   &&
        UpperBitsNotSet64(p->L_PACKET,          13)  &&
        UpperBitsNotSet64(p->Q_SCALE,           2)   &&
        UpperBitsNotSet64(p->Q_TRACKINIT,       1)   &&
        UpperBitsNotSet64(p->D_TRACKINIT,       15)  &&
        UpperBitsNotSet64(p->D_TRACKCOND,       15)  &&
        UpperBitsNotSet64(p->L_TRACKCOND,       15)  &&
        UpperBitsNotSet64(p->M_PLATFORM,        4)   &&
        UpperBitsNotSet64(p->Q_PLATFORM,        2)   &&
        UpperBitsNotSet64(p->N_ITER_1,          5))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

