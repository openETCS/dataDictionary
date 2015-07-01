
#include "National_Values_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"
#include "National_Values_Core_1_UpperBitsNotSet.h"
#include "National_Values_Core_2_UpperBitsNotSet.h"
#include "National_Values_Core_3_UpperBitsNotSet.h"
#include "National_Values_Core_4_UpperBitsNotSet.h"

int National_Values_UpperBitsNotSet(const National_Values_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->D_VALIDNV,         15);
    status = status && UpperBitsNotSet64(p->NID_C,             10);
    status = status && UpperBitsNotSet64(p->N_ITER_1,          5) ;
    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        status = status && National_Values_Core_1_UpperBitsNotSet(&(p->sub_1[i]));
    }
    status = status && UpperBitsNotSet64(p->V_NVSHUNT,         7) ;
    status = status && UpperBitsNotSet64(p->V_NVSTFF,          7) ;
    status = status && UpperBitsNotSet64(p->V_NVONSIGHT,       7) ;
    status = status && UpperBitsNotSet64(p->V_NVLIMSUPERV,     7) ;
    status = status && UpperBitsNotSet64(p->V_NVUNFIT,         7) ;
    status = status && UpperBitsNotSet64(p->V_NVREL,           7) ;
    status = status && UpperBitsNotSet64(p->D_NVROLL,          15);
    status = status && UpperBitsNotSet64(p->Q_NVSBTSMPERM,     1) ;
    status = status && UpperBitsNotSet64(p->Q_NVEMRRLS,        1) ;
    status = status && UpperBitsNotSet64(p->Q_NVGUIPERM,       1) ;
    status = status && UpperBitsNotSet64(p->Q_NVSBFBPERM,      1) ;
    status = status && UpperBitsNotSet64(p->Q_NVINHSMICPERM,   1) ;
    status = status && UpperBitsNotSet64(p->V_NVALLOWOVTRP,    7) ;
    status = status && UpperBitsNotSet64(p->V_NVSUPOVTRP,      7) ;
    status = status && UpperBitsNotSet64(p->D_NVOVTRP,         15);
    status = status && UpperBitsNotSet64(p->T_NVOVTRP,         8) ;
    status = status && UpperBitsNotSet64(p->D_NVPOTRP,         15);
    status = status && UpperBitsNotSet64(p->M_NVCONTACT,       2) ;
    status = status && UpperBitsNotSet64(p->T_NVCONTACT,       8) ;
    status = status && UpperBitsNotSet64(p->M_NVDERUN,         1) ;
    status = status && UpperBitsNotSet64(p->D_NVSTFF,          15);
    status = status && UpperBitsNotSet64(p->Q_NVDRIVER_ADHES,  1) ;
    status = status && UpperBitsNotSet64(p->A_NVMAXREDADH1,    6) ;
    status = status && UpperBitsNotSet64(p->A_NVMAXREDADH2,    6) ;
    status = status && UpperBitsNotSet64(p->A_NVMAXREDADH3,    6) ;
    status = status && UpperBitsNotSet64(p->Q_NVLOCACC,        6) ;
    status = status && UpperBitsNotSet64(p->M_NVAVADH,         5) ;
    status = status && UpperBitsNotSet64(p->M_NVEBCL,          4) ;
    status = status && UpperBitsNotSet64(p->Q_NVKINT,          1) ;
    if (p->Q_NVKINT == 1)
    {
    status = status && UpperBitsNotSet64(p->Q_NVKVINTSET,      2) ;
    if (p->Q_NVKVINTSET == 1)
    {
    status = status && UpperBitsNotSet64(p->A_NVP12,           6) ;
    status = status && UpperBitsNotSet64(p->A_NVP23,           6) ;
    }
    status = status && UpperBitsNotSet64(p->V_NVKVINT,         7) ;
    status = status && UpperBitsNotSet64(p->M_NVKVINT,         7) ;
    status = status && UpperBitsNotSet64(p->N_ITER_2,          5) ;
    for (uint32_t i = 0; i < p->N_ITER_2; ++i)
    {
        status = status && National_Values_Core_2_UpperBitsNotSet(&(p->sub_2[i]));
    }
    status = status && UpperBitsNotSet64(p->N_ITER_3,          5) ;
    for (uint32_t i = 0; i < p->N_ITER_3; ++i)
    {
        status = status && National_Values_Core_3_UpperBitsNotSet(&(p->sub_3[i]));
    }
    status = status && UpperBitsNotSet64(p->L_NVKRINT,         5) ;
    status = status && UpperBitsNotSet64(p->M_NVKRINT,         5) ;
    status = status && UpperBitsNotSet64(p->N_ITER_4,          5) ;
    for (uint32_t i = 0; i < p->N_ITER_4; ++i)
    {
        status = status && National_Values_Core_4_UpperBitsNotSet(&(p->sub_4[i]));
    }
    status = status && UpperBitsNotSet64(p->M_NVKTINT,         5) ;
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

