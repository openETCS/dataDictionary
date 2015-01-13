
#include "Gradient_Profile_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Gradient_Profile_UpperBitsNotSet(const Gradient_Profile* p)
{
    if (UpperBitsNotSet64(p->NID_PACKET,        8)   &&
        UpperBitsNotSet64(p->Q_DIR,             2)   &&
        UpperBitsNotSet64(p->L_PACKET,          13)  &&
        UpperBitsNotSet64(p->Q_SCALE,           2)   &&
        UpperBitsNotSet64(p->D_GRADIENT,        15)  &&
        UpperBitsNotSet64(p->Q_GDIR,            1)   &&
        UpperBitsNotSet64(p->G_A,               8)   &&
        UpperBitsNotSet64(p->N_ITER,            5)   &&
        UpperBitsNotSet64(p->D_GRADIENT(k),     15)  &&
        UpperBitsNotSet64(p->Q_GDIR(k),         1)   &&
        UpperBitsNotSet64(p->G_A(k),            8))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

