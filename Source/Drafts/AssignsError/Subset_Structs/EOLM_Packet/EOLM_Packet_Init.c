
#include "EOLM_Packet_Init.h"

void EOLM_Packet_Init(EOLM_Packet* p)
{
    p->Q_DIR             = 0;
    p->L_PACKET          = 0;
    p->Q_SCALE           = 0;
    p->NID_LOOP          = 0;
    p->D_LOOP            = 0;
    p->L_LOOP            = 0;
    p->Q_LOOPDIR         = 0;
    p->Q_SSCODE          = 0;
}

