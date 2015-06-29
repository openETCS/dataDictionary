
#include "Permitted_Braking_Distance_Information_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"
#include "Permitted_Braking_Distance_Information_Core_1_UpperBitsNotSet.h"

int Permitted_Braking_Distance_Information_UpperBitsNotSet(const Permitted_Braking_Distance_Information_Core* p)
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
    status = status && UpperBitsNotSet64(p->D_PBD,             15);
    status = status && UpperBitsNotSet64(p->Q_GDIR,            1) ;
    status = status && UpperBitsNotSet64(p->G_PBDSR,           8) ;
    status = status && UpperBitsNotSet64(p->Q_PBDSR,           1) ;
    status = status && UpperBitsNotSet64(p->D_PBDSR,           15);
    status = status && UpperBitsNotSet64(p->L_PBDSR,           15);
    status = status && UpperBitsNotSet64(p->N_ITER_1,          5) ;
    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        status = status && Permitted_Braking_Distance_Information_Core_1_UpperBitsNotSet(&(p->sub_1[i]));
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

