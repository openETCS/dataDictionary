
#include "Train_running_number_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Train_running_number_UpperBitsNotSet(const Train_running_number* p)
{
    if (UpperBitsNotSet64(p->L_PACKET,          13)  &&
        UpperBitsNotSet64(p->NID_OPERATIONAL,   32))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

