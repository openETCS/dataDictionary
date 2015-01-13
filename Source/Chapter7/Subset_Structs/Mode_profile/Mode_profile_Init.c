
#include "Mode_profile_Init.h"

void Mode_profile_Init(Mode_profile* p)
{
    p->NID_PACKET        = 0;
    p->Q_DIR             = 0;
    p->L_PACKET          = 0;
    p->Q_SCALE           = 0;
    p->D_MAMODE          = 0;
    p->M_MAMODE          = 0;
    p->V_MAMODE          = 0;
    p->L_MAMODE          = 0;
    p->L_ACKMAMODE       = 0;
    p->Q_MAMODE          = 0;
    p->N_ITER            = 0;
}

