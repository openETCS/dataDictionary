
#include "Train_running_number_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Train_running_number_UpperBitsNotSet(const Train_running_number_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->NID_OPERATIONAL,   32);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

