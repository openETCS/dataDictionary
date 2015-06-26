
#include "Level_23_Movement_Authority_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Level_23_Movement_Authority_UpperBitsNotSet(const Level_23_Movement_Authority_Core* p)
{
    if (UpperBitsNotSet64(p->Q_DIR,             2)   &&
        UpperBitsNotSet64(p->L_PACKET,          13)  &&
        UpperBitsNotSet64(p->Q_SCALE,           2)   &&
        UpperBitsNotSet64(p->V_LOA,             7)   &&
        UpperBitsNotSet64(p->T_LOA,             10)  &&
        UpperBitsNotSet64(p->N_ITER_1,          5)   &&
        UpperBitsNotSet64(p->L_ENDSECTION,      15)  &&
        UpperBitsNotSet64(p->Q_SECTIONTIMER,    1)   &&
        UpperBitsNotSet64(p->T_SECTIONTIMER,    10)  &&
        UpperBitsNotSet64(p->D_SECTIONTIMERSTOPLOC, 15)  &&
        UpperBitsNotSet64(p->Q_ENDTIMER,        1)   &&
        UpperBitsNotSet64(p->T_ENDTIMER,        10)  &&
        UpperBitsNotSet64(p->D_ENDTIMERSTARTLOC, 15)  &&
        UpperBitsNotSet64(p->Q_DANGERPOINT,     1)   &&
        UpperBitsNotSet64(p->D_DP,              15)  &&
        UpperBitsNotSet64(p->V_RELEASEDP,       7)   &&
        UpperBitsNotSet64(p->Q_OVERLAP,         1)   &&
        UpperBitsNotSet64(p->D_STARTOL,         15)  &&
        UpperBitsNotSet64(p->T_OL,              10)  &&
        UpperBitsNotSet64(p->D_OL,              15)  &&
        UpperBitsNotSet64(p->V_RELEASEOL,       7))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

