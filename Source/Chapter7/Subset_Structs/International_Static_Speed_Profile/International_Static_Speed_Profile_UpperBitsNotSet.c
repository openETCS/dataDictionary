
#include "International_Static_Speed_Profile_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int International_Static_Speed_Profile_UpperBitsNotSet(const International_Static_Speed_Profile* p)
{
    if (UpperBitsNotSet64(p->NID_PACKET,        8)   &&
        UpperBitsNotSet64(p->Q_DIR,             2)   &&
        UpperBitsNotSet64(p->L_PACKET,          13)  &&
        UpperBitsNotSet64(p->Q_SCALE,           2)   &&
        UpperBitsNotSet64(p->D_STATIC,          15)  &&
        UpperBitsNotSet64(p->V_STATIC,          7)   &&
        UpperBitsNotSet64(p->Q_FRONT,           1)   &&
        UpperBitsNotSet64(p->N_ITER,            5)   &&
        UpperBitsNotSet64(p->Q_DIFF(n),         2)   &&
        UpperBitsNotSet64(p->NC_CDDIFF(n),      4)   &&
        UpperBitsNotSet64(p->NC_DIFF(n),        4)   &&
        UpperBitsNotSet64(p->V_DIFF(n),         7)   &&
        UpperBitsNotSet64(p->N_ITER,            5)   &&
        UpperBitsNotSet64(p->D_STATIC(k),       15)  &&
        UpperBitsNotSet64(p->V_STATIC(k),       7)   &&
        UpperBitsNotSet64(p->Q_FRONT(k),        1)   &&
        UpperBitsNotSet64(p->N_ITER(k),         5)   &&
        UpperBitsNotSet64(p->Q_DIFF(k,m),       2)   &&
        UpperBitsNotSet64(p->NC_CDDIFF(k,m),    4)   &&
        UpperBitsNotSet64(p->NC_DIFF(k,m),      4)   &&
        UpperBitsNotSet64(p->V_DIFF(k,m),       7))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

