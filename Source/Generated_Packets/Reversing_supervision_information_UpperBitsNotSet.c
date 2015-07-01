
#include "Reversing_supervision_information_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Reversing_supervision_information_UpperBitsNotSet(const Reversing_supervision_information_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->D_REVERSE,         15);
    status = status && UpperBitsNotSet64(p->V_REVERSE,         7) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

