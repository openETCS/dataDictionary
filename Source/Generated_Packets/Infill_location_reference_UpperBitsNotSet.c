
#include "Infill_location_reference_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Infill_location_reference_UpperBitsNotSet(const Infill_location_reference_Core* p)
{
    if (UpperBitsNotSet64(p->Q_DIR,             2)   &&
        UpperBitsNotSet64(p->L_PACKET,          13)  &&
        UpperBitsNotSet64(p->Q_NEWCOUNTRY,      1)   &&
        UpperBitsNotSet64(p->NID_C,             10)  &&
        UpperBitsNotSet64(p->NID_BG,            14))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

