
#include "Onboard_telephone_numbers_Core_1_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Onboard_telephone_numbers_Core_1_UpperBitsNotSet(const Onboard_telephone_numbers_Core_1* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->NID_RADIO_k,       64);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

