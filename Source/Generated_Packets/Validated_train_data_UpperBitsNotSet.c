
#include "Validated_train_data_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Validated_train_data_UpperBitsNotSet(const Validated_train_data_Core* p)
{
    if (UpperBitsNotSet64(p->L_PACKET,          13)  &&
        UpperBitsNotSet64(p->NC_CDTRAIN,        4)   &&
        UpperBitsNotSet64(p->NC_TRAIN,          15)  &&
        UpperBitsNotSet64(p->L_TRAIN,           12)  &&
        UpperBitsNotSet64(p->V_MAXTRAIN,        7)   &&
        UpperBitsNotSet64(p->M_LOADINGGAUGE,    8)   &&
        UpperBitsNotSet64(p->M_AXLELOADCAT,     7)   &&
        UpperBitsNotSet64(p->M_AIRTIGHT,        2)   &&
        UpperBitsNotSet64(p->N_AXLE,            10))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

