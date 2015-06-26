
#include "Validated_train_data_Core_2_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Validated_train_data_Core_2_UpperBitsNotSet(const Validated_train_data_Core_2* p)
{
    if (UpperBitsNotSet64(p->NID_NTC_n,         8))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

