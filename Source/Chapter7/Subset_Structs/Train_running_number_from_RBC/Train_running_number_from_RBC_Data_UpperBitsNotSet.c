
#include "Train_running_number_from_RBC_Data_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Train_running_number_from_RBC_Data_UpperBitsNotSet(const Train_running_number_from_RBC_Data* p)
{
    if (UpperBitsNotSet64(p->Q_DIR,             2)   &&
        UpperBitsNotSet64(p->NID_OPERATIONAL,   32))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

