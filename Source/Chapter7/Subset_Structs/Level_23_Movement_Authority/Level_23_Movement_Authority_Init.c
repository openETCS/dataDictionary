
#include "Level_23_Movement_Authority_Init.h"

void Level_23_Movement_Authority_Init(Level_23_Movement_Authority* p)
{
    p->NID_PACKET        = 0;
    p->Q_DIR             = 0;
    p->L_PACKET          = 0;
    p->Q_SCALE           = 0;
    p->V_LOA             = 0;
    p->T_LOA             = 0;
    p->N_ITER            = 0;
    p->L_ENDSECTION      = 0;
    p->Q_SECTIONTIMER    = 0;
    p->T_SECTIONTIMER    = 0;
    p->D_SECTIONTIMERSTOPLOC= 0;
    p->Q_ENDTIMER        = 0;
    p->T_ENDTIMER        = 0;
    p->D_ENDTIMERSTARTLOC= 0;
    p->Q_DANGERPOINT     = 0;
    p->D_DP              = 0;
    p->V_RELEASEDP       = 0;
    p->Q_OVERLAP         = 0;
    p->D_STARTOL         = 0;
    p->T_OL              = 0;
    p->D_OL              = 0;
    p->V_RELEASEOL       = 0;
}

