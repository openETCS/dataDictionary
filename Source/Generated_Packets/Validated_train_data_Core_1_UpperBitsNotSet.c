
#include "Validated_train_data_Core_1_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Validated_train_data_Core_1_UpperBitsNotSet(const Validated_train_data_Core_1* p)
{
    if (UpperBitsNotSet64(p->M_VOLTAGE_k,       4)   &&
        UpperBitsNotSet64(p->NID_CTRACTION_k,   10))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

