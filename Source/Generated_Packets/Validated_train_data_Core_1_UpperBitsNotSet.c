
#include "Validated_train_data_Core_1_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Validated_train_data_Core_1_UpperBitsNotSet(const Validated_train_data_Core_1* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->M_VOLTAGE_k,       4) ;
    if ((p->M_VOLTAGE_k != 0) && (p->NID_CTRACTION_k != 0))
    {
    status = status && UpperBitsNotSet64(p->NID_CTRACTION_k,   10);
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

