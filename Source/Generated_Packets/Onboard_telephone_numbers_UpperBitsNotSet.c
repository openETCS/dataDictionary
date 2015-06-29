
#include "Onboard_telephone_numbers_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"
#include "Onboard_telephone_numbers_Core_1_UpperBitsNotSet.h"

int Onboard_telephone_numbers_UpperBitsNotSet(const Onboard_telephone_numbers_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->N_ITER_1,          5) ;
    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        status = status && Onboard_telephone_numbers_Core_1_UpperBitsNotSet(&(p->sub_1[i]));
    }

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

