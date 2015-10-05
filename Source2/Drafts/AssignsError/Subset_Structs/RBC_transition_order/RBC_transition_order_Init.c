
#include "RBC_transition_order_Init.h"

void RBC_transition_order_Init(RBC_transition_order* p)
{
    p->Q_DIR             = 0;
    p->L_PACKET          = 0;
    p->Q_SCALE           = 0;
    p->D_RBCTR           = 0;
    p->NID_C             = 0;
    p->NID_RBC           = 0;
    p->NID_RADIO         = 0;
    p->Q_SLEEPSESSION    = 0;
}

