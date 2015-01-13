
#include "Track_Ahead_Free_up_to_level_23_transition_location_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Track_Ahead_Free_up_to_level_23_transition_location_UpperBitsNotSet(const Track_Ahead_Free_up_to_level_23_transition_location* p)
{
    if (UpperBitsNotSet64(p->NID_PACKET,        8)   &&
        UpperBitsNotSet64(p->Q_DIR,             2)   &&
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

