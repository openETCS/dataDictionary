
#include "Route_Suitability_Data_Init.h"

void Route_Suitability_Data_Init(Route_Suitability_Data* p)
{
    p->NID_PACKET        = 0;
    p->Q_DIR             = 0;
    p->L_PACKET          = 0;
    p->Q_SCALE           = 0;
    p->Q_TRACKINIT       = 0;
    p->D_TRACKINIT       = 0;
    p->D_SUITABILITY     = 0;
    p->Q_SUITABILITY     = 0;
    p->M_LINEGAUGE       = 0;
    p->M_AXLELOADCAT     = 0;
    p->M_VOLTAGE         = 0;
    p->NID_CTRACTION     = 0;
    p->N_ITER            = 0;
}

