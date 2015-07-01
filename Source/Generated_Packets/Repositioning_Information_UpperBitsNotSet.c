
#include "Repositioning_Information_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Repositioning_Information_UpperBitsNotSet(const Repositioning_Information_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->L_SECTION,         15);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

