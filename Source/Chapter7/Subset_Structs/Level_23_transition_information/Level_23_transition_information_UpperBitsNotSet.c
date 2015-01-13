
#include "Level_23_transition_information_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Level_23_transition_information_UpperBitsNotSet(const Level_23_transition_information* p)
{
    if (UpperBitsNotSet64(p->NID_PACKET,        8)   &&
        UpperBitsNotSet64(p->L_PACKET,          13)  &&
        UpperBitsNotSet64(p->NID_LTRBG,         24))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

