
#include "Radio_infill_area_information_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Radio_infill_area_information_UpperBitsNotSet(const Radio_infill_area_information_Core* p)
{
    if (UpperBitsNotSet64(p->Q_DIR,             2)   &&
        UpperBitsNotSet64(p->L_PACKET,          13)  &&
        UpperBitsNotSet64(p->Q_SCALE,           2)   &&
        UpperBitsNotSet64(p->Q_RIU,             1)   &&
        UpperBitsNotSet64(p->NID_C,             10)  &&
        UpperBitsNotSet64(p->NID_RIU,           14)  &&
        UpperBitsNotSet64(p->NID_RADIO,         64)  &&
        UpperBitsNotSet64(p->D_INFILL,          15)  &&
        UpperBitsNotSet64(p->NID_BG,            14))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

