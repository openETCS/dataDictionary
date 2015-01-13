
#include "Onboard_telephone_numbers_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Onboard_telephone_numbers_UpperBitsNotSet(const Onboard_telephone_numbers* p)
{
    if (UpperBitsNotSet64(p->NID_PACKET,        8)   &&
        UpperBitsNotSet64(p->L_PACKET,          13)  &&
        UpperBitsNotSet64(p->N_ITER,            5)   &&
        UpperBitsNotSet64(p->NID_RADIO_(k),     64))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

