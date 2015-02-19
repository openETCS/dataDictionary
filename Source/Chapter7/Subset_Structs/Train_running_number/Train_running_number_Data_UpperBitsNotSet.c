
#include "Train_running_number_Data_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Train_running_number_Data_UpperBitsNotSet(const Train_running_number_Data* p)
{
    if (UpperBitsNotSet64(p->NID_OPERATIONAL,   32))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

