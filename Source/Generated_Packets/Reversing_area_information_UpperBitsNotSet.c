
#include "Reversing_area_information_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Reversing_area_information_UpperBitsNotSet(const Reversing_area_information_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->D_STARTREVERSE,    15);
    status = status && UpperBitsNotSet64(p->L_REVERSEAREA,     15);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

