
#include "Track_Condition_Init.h"

void Track_Condition_Init(Track_Condition* p)
{
    p->NID_PACKET        = 0;
    p->Q_DIR             = 0;
    p->L_PACKET          = 0;
    p->Q_SCALE           = 0;
    p->Q_TRACKINIT       = 0;
    p->D_TRACKINIT       = 0;
    p->D_TRACKCOND       = 0;
    p->L_TRACKCOND       = 0;
    p->M_TRACKCOND       = 0;
    p->N_ITER            = 0;
}

