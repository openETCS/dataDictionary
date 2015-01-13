
#include "Temporary_Speed_Restriction_Init.h"

void Temporary_Speed_Restriction_Init(Temporary_Speed_Restriction* p)
{
    p->NID_PACKET        = 0;
    p->Q_DIR             = 0;
    p->L_PACKET          = 0;
    p->Q_SCALE           = 0;
    p->NID_TSR           = 0;
    p->D_TSR             = 0;
    p->L_TSR             = 0;
    p->Q_FRONT           = 0;
    p->V_TSR             = 0;
}

