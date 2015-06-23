
#include "National_Values_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int National_Values_UpperBitsNotSet(const National_Values_Core* p)
{
    if (UpperBitsNotSet64(p->Q_DIR,             2)   &&
        UpperBitsNotSet64(p->L_PACKET,          13)  &&
        UpperBitsNotSet64(p->Q_SCALE,           2)   &&
        UpperBitsNotSet64(p->D_VALIDNV,         15)  &&
        UpperBitsNotSet64(p->NID_C,             10)  &&
        UpperBitsNotSet64(p->V_NVSHUNT,         7)   &&
        UpperBitsNotSet64(p->V_NVSTFF,          7)   &&
        UpperBitsNotSet64(p->V_NVONSIGHT,       7)   &&
        UpperBitsNotSet64(p->V_NVLIMSUPERV,     7)   &&
        UpperBitsNotSet64(p->V_NVUNFIT,         7)   &&
        UpperBitsNotSet64(p->V_NVREL,           7)   &&
        UpperBitsNotSet64(p->D_NVROLL,          15)  &&
        UpperBitsNotSet64(p->Q_NVSBTSMPERM,     1)   &&
        UpperBitsNotSet64(p->Q_NVEMRRLS,        1)   &&
        UpperBitsNotSet64(p->Q_NVGUIPERM,       1)   &&
        UpperBitsNotSet64(p->Q_NVSBFBPERM,      1)   &&
        UpperBitsNotSet64(p->Q_NVINHSMICPERM,   1)   &&
        UpperBitsNotSet64(p->V_NVALLOWOVTRP,    7)   &&
        UpperBitsNotSet64(p->V_NVSUPOVTRP,      7)   &&
        UpperBitsNotSet64(p->D_NVOVTRP,         15)  &&
        UpperBitsNotSet64(p->T_NVOVTRP,         8)   &&
        UpperBitsNotSet64(p->D_NVPOTRP,         15)  &&
        UpperBitsNotSet64(p->M_NVCONTACT,       2)   &&
        UpperBitsNotSet64(p->T_NVCONTACT,       8)   &&
        UpperBitsNotSet64(p->M_NVDERUN,         1)   &&
        UpperBitsNotSet64(p->D_NVSTFF,          15)  &&
        UpperBitsNotSet64(p->Q_NVDRIVER_ADHES,  1)   &&
        UpperBitsNotSet64(p->A_NVMAXREDADH1,    6)   &&
        UpperBitsNotSet64(p->A_NVMAXREDADH2,    6)   &&
        UpperBitsNotSet64(p->A_NVMAXREDADH3,    6)   &&
        UpperBitsNotSet64(p->Q_NVLOCACC,        6)   &&
        UpperBitsNotSet64(p->M_NVAVADH,         5)   &&
        UpperBitsNotSet64(p->M_NVEBCL,          4)   &&
        UpperBitsNotSet64(p->Q_NVKINT,          1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

