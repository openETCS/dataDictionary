
#include "EOLM_Packet_Data_Init.h"

void EOLM_Packet_Data_Init(EOLM_Packet_Data* p)
{
    p->Q_DIR             = 0;
    p->Q_SCALE           = 0;
    p->NID_LOOP          = 0;
    p->D_LOOP            = 0;
    p->L_LOOP            = 0;
    p->Q_LOOPDIR         = 0;
    p->Q_SSCODE          = 0;
}

