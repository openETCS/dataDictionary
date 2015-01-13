
#include "Axle_Load_Speed_Profile_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Axle_Load_Speed_Profile_UpperBitsNotSet(const Axle_Load_Speed_Profile* p)
{
    if (UpperBitsNotSet64(p->NID_PACKET,        8)   &&
        UpperBitsNotSet64(p->Q_DIR,             2)   &&
        UpperBitsNotSet64(p->L_PACKET,          13)  &&
        UpperBitsNotSet64(p->Q_SCALE,           2)   &&
        UpperBitsNotSet64(p->Q_TRACKINIT,       1)   &&
        UpperBitsNotSet64(p->D_TRACKINIT,       15)  &&
        UpperBitsNotSet64(p->D_AXLELOAD,        15)  &&
        UpperBitsNotSet64(p->L_AXLELOAD,        15)  &&
        UpperBitsNotSet64(p->Q_FRONT,           1)   &&
        UpperBitsNotSet64(p->N_ITER,            5)   &&
        UpperBitsNotSet64(p->M_AXLELOADCAT(n),  7)   &&
        UpperBitsNotSet64(p->V_AXLELOAD(n),     7)   &&
        UpperBitsNotSet64(p->N_ITER,            5)   &&
        UpperBitsNotSet64(p->D_AXLELOAD(k),     15)  &&
        UpperBitsNotSet64(p->L_AXLELOAD(k),     15)  &&
        UpperBitsNotSet64(p->Q_FRONT(k),        1)   &&
        UpperBitsNotSet64(p->N_ITER(k),         5)   &&
        UpperBitsNotSet64(p->M_AXLELOADCAT(k,m), 7)   &&
        UpperBitsNotSet64(p->V_AXLELOAD(k,m),   7))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

