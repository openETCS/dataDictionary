
#include "Radio_infill_area_information_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Radio_infill_area_information_UpperBitsNotSet(const Radio_infill_area_information_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->Q_RIU,             1) ;
    status = status && UpperBitsNotSet64(p->NID_C,             10);
    status = status && UpperBitsNotSet64(p->NID_RIU,           14);
    status = status && UpperBitsNotSet64(p->NID_RADIO,         64);
    status = status && UpperBitsNotSet64(p->D_INFILL,          15);
    status = status && UpperBitsNotSet64(p->NID_BG,            14);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

