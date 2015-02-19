
#include "Level_23_transition_information_Data_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Level_23_transition_information_Data_UpperBitsNotSet(const Level_23_transition_information_Data* p)
{
    if (UpperBitsNotSet64(p->NID_LTRBG,         24))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

