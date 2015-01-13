
#include "Virtual_Balise_Cover_order_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Virtual_Balise_Cover_order_UpperBitsNotSet(const Virtual_Balise_Cover_order* p)
{
    if (UpperBitsNotSet64(p->NID_PACKET,        8)   &&
        UpperBitsNotSet64(p->Q_DIR,             2)   &&
        UpperBitsNotSet64(p->L_PACKET,          13)  &&
        UpperBitsNotSet64(p->Q_VBCO,            1)   &&
        UpperBitsNotSet64(p->NID_VBCMK,         6)   &&
        UpperBitsNotSet64(p->NID_C,             10)  &&
        UpperBitsNotSet64(p->T_VBC,             8))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

