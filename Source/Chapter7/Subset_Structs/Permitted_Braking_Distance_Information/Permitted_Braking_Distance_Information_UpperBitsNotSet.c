
#include "Permitted_Braking_Distance_Information_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Permitted_Braking_Distance_Information_UpperBitsNotSet(const Permitted_Braking_Distance_Information* p)
{
    if (UpperBitsNotSet64(p->NID_PACKET,        8)   &&
        UpperBitsNotSet64(p->Q_DIR,             2)   &&
        UpperBitsNotSet64(p->L_PACKET,          13)  &&
        UpperBitsNotSet64(p->Q_SCALE,           2)   &&
        UpperBitsNotSet64(p->Q_TRACKINIT,       1)   &&
        UpperBitsNotSet64(p->D_TRACKINIT,       15)  &&
        UpperBitsNotSet64(p->D_PBD,             15)  &&
        UpperBitsNotSet64(p->Q_GDIR,            1)   &&
        UpperBitsNotSet64(p->G_PBDSR,           8)   &&
        UpperBitsNotSet64(p->Q_PBDSR,           1)   &&
        UpperBitsNotSet64(p->D_PBDSR,           15)  &&
        UpperBitsNotSet64(p->L_PBDSR,           15)  &&
        UpperBitsNotSet64(p->N_ITER,            5)   &&
        UpperBitsNotSet64(p->D_PBD(k),          15)  &&
        UpperBitsNotSet64(p->Q_GDIR(k),         1)   &&
        UpperBitsNotSet64(p->G_PBDSR(k),        8)   &&
        UpperBitsNotSet64(p->Q_PBDSR(k),        1)   &&
        UpperBitsNotSet64(p->D_PBDSR(k),        15)  &&
        UpperBitsNotSet64(p->L_PBDSR(k),        15))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

