
#include "Level_Crossing_information_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Level_Crossing_information_UpperBitsNotSet(const Level_Crossing_information_Core* p)
{
    if (UpperBitsNotSet64(p->Q_DIR,             2)   &&
        UpperBitsNotSet64(p->L_PACKET,          13)  &&
        UpperBitsNotSet64(p->Q_SCALE,           2)   &&
        UpperBitsNotSet64(p->NID_LX,            8)   &&
        UpperBitsNotSet64(p->D_LX,              15)  &&
        UpperBitsNotSet64(p->L_LX,              15)  &&
        UpperBitsNotSet64(p->Q_LXSTATUS,        1)   &&
        UpperBitsNotSet64(p->V_LX,              7)   &&
        UpperBitsNotSet64(p->Q_STOPLX,          1)   &&
        UpperBitsNotSet64(p->L_STOPLX,          15))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

