
#include "Onboard_telephone_numbers_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Onboard_telephone_numbers_UpperBitsNotSet(const Onboard_telephone_numbers_Core* p)
{
    if (UpperBitsNotSet64(p->L_PACKET,          13))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

