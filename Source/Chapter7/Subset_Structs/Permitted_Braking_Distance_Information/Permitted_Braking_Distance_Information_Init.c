
#include "Permitted_Braking_Distance_Information_Init.h"

void Permitted_Braking_Distance_Information_Init(Permitted_Braking_Distance_Information* p)
{
    p->NID_PACKET        = 0;
    p->Q_DIR             = 0;
    p->L_PACKET          = 0;
    p->Q_SCALE           = 0;
    p->Q_TRACKINIT       = 0;
    p->D_TRACKINIT       = 0;
    p->D_PBD             = 0;
    p->Q_GDIR            = 0;
    p->G_PBDSR           = 0;
    p->Q_PBDSR           = 0;
    p->D_PBDSR           = 0;
    p->L_PBDSR           = 0;
    p->N_ITER            = 0;
}

