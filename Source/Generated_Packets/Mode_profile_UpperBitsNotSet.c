
#include "Mode_profile_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"
#include "Mode_profile_Core_1_UpperBitsNotSet.h"

int Mode_profile_UpperBitsNotSet(const Mode_profile_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->D_MAMODE,          15);
    status = status && UpperBitsNotSet64(p->M_MAMODE,          2) ;
    status = status && UpperBitsNotSet64(p->V_MAMODE,          7) ;
    status = status && UpperBitsNotSet64(p->L_MAMODE,          15);
    status = status && UpperBitsNotSet64(p->L_ACKMAMODE,       15);
    status = status && UpperBitsNotSet64(p->Q_MAMODE,          1) ;
    status = status && UpperBitsNotSet64(p->N_ITER_1,          5) ;
    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        status = status && Mode_profile_Core_1_UpperBitsNotSet(&(p->sub_1[i]));
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

