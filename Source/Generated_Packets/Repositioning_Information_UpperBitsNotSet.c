
#include "Repositioning_Information_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Repositioning_Information_UpperBitsNotSet(const Repositioning_Information_Core* p)
{
    if (UpperBitsNotSet64(p->Q_DIR,             2)   &&
        UpperBitsNotSet64(p->L_PACKET,          13)  &&
        UpperBitsNotSet64(p->Q_SCALE,           2)   &&
        UpperBitsNotSet64(p->L_SECTION,         15))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

