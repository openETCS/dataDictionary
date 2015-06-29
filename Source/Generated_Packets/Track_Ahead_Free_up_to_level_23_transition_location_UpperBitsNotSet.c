
#include "Track_Ahead_Free_up_to_level_23_transition_location_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Track_Ahead_Free_up_to_level_23_transition_location_UpperBitsNotSet(const Track_Ahead_Free_up_to_level_23_transition_location_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_NEWCOUNTRY,      1) ;
    if (p->Q_NEWCOUNTRY == 1)
    {
    status = status && UpperBitsNotSet64(p->NID_C,             10);
    }
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

