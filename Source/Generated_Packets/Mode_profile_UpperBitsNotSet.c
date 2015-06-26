
#include "Mode_profile_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Mode_profile_UpperBitsNotSet(const Mode_profile_Core* p)
{
    if (UpperBitsNotSet64(p->Q_DIR,             2)   &&
        UpperBitsNotSet64(p->L_PACKET,          13)  &&
        UpperBitsNotSet64(p->Q_SCALE,           2)   &&
        UpperBitsNotSet64(p->D_MAMODE,          15)  &&
        UpperBitsNotSet64(p->M_MAMODE,          2)   &&
        UpperBitsNotSet64(p->V_MAMODE,          7)   &&
        UpperBitsNotSet64(p->L_MAMODE,          15)  &&
        UpperBitsNotSet64(p->L_ACKMAMODE,       15)  &&
        UpperBitsNotSet64(p->Q_MAMODE,          1)   &&
        UpperBitsNotSet64(p->N_ITER_1,          5))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

