
#include "Session_Management_Init.h"

void Session_Management_Init(Session_Management* p)
{
    p->Q_DIR             = 0;
    p->L_PACKET          = 0;
    p->Q_RBC             = 0;
    p->NID_C             = 0;
    p->NID_RBC           = 0;
    p->NID_RADIO         = 0;
    p->Q_SLEEPSESSION    = 0;
}

