
#include "Linking_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Linking_UpperBitsNotSet(const Linking* p)
{
    if (UpperBitsNotSet64(p->NID_PACKET,        8)   &&
        UpperBitsNotSet64(p->Q_DIR,             2)   &&
        UpperBitsNotSet64(p->L_PACKET,          13)  &&
        UpperBitsNotSet64(p->Q_SCALE,           2)   &&
        UpperBitsNotSet64(p->D_LINK,            15)  &&
        UpperBitsNotSet64(p->Q_NEWCOUNTRY,      1)   &&
        UpperBitsNotSet64(p->NID_C,             10)  &&
        UpperBitsNotSet64(p->NID_BG,            14)  &&
        UpperBitsNotSet64(p->Q_LINKORIENTATION, 1)   &&
        UpperBitsNotSet64(p->Q_LINKREACTION,    2)   &&
        UpperBitsNotSet64(p->Q_LOCACC,          6)   &&
        UpperBitsNotSet64(p->N_ITER,            5)   &&
        UpperBitsNotSet64(p->D_LINK_(k),        15)  &&
        UpperBitsNotSet64(p->Q_NEWCOUNTRY(k),   1)   &&
        UpperBitsNotSet64(p->NID_C_(k),         10)  &&
        UpperBitsNotSet64(p->NID_BG_(k),        14)  &&
        UpperBitsNotSet64(p->Q_LINKORIENTATION_(k), 1)   &&
        UpperBitsNotSet64(p->Q_LINKREACTION_(k), 2)   &&
        UpperBitsNotSet64(p->Q_LOCACC_(k),      6))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

