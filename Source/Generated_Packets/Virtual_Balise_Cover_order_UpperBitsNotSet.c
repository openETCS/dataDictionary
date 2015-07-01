
#include "Virtual_Balise_Cover_order_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Virtual_Balise_Cover_order_UpperBitsNotSet(const Virtual_Balise_Cover_order_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_VBCO,            1) ;
    status = status && UpperBitsNotSet64(p->NID_VBCMK,         6) ;
    status = status && UpperBitsNotSet64(p->NID_C,             10);
    if (p->Q_VBCO == 1)
    {
    status = status && UpperBitsNotSet64(p->T_VBC,             8) ;
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

