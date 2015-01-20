
#include "Adhesion_Factor_Init.h"

void Adhesion_Factor_Init(Adhesion_Factor* p)
{
    p->Header.NID_PACKET        = 0;
    p->Header.Q_DIR             = 0;
    p->Header.L_PACKET          = 0;
    p->Data.Q_SCALE           = 0;
    p->Data.D_ADHESION        = 0;
    p->Data.L_ADHESION        = 0;
    p->Data.M_ADHESION        = 0;
}

