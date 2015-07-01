
#include "Level_Crossing_information_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Level_Crossing_information_UpperBitsNotSet(const Level_Crossing_information_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->NID_LX,            8) ;
    status = status && UpperBitsNotSet64(p->D_LX,              15);
    status = status && UpperBitsNotSet64(p->L_LX,              15);
    status = status && UpperBitsNotSet64(p->Q_LXSTATUS,        1) ;
    if (p->Q_LXSTATUS == 1)
    {
    status = status && UpperBitsNotSet64(p->V_LX,              7) ;
    status = status && UpperBitsNotSet64(p->Q_STOPLX,          1) ;
    }
    if (p->Q_STOPLX == 1)
    {
    status = status && UpperBitsNotSet64(p->L_STOPLX,          15);
    }

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

