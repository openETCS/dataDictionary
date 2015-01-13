
#include "Track_Condition_Station_Platforms_Init.h"

void Track_Condition_Station_Platforms_Init(Track_Condition_Station_Platforms* p)
{
    p->NID_PACKET        = 0;
    p->Q_DIR             = 0;
    p->L_PACKET          = 0;
    p->Q_SCALE           = 0;
    p->Q_TRACKINIT       = 0;
    p->D_TRACKINIT       = 0;
    p->D_TRACKCOND       = 0;
    p->L_TRACKCOND       = 0;
    p->M_PLATFORM        = 0;
    p->Q_PLATFORM        = 0;
    p->N_ITER            = 0;
}

