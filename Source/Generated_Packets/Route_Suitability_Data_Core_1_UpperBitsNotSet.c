
#include "Route_Suitability_Data_Core_1_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Route_Suitability_Data_Core_1_UpperBitsNotSet(const Route_Suitability_Data_Core_1* p)
{
    if (UpperBitsNotSet64(p->D_SUITABILITY_k,   15)  &&
        UpperBitsNotSet64(p->Q_SUITABILITY_k,   2)   &&
        UpperBitsNotSet64(p->M_LINEGAUGE_k,     8)   &&
        UpperBitsNotSet64(p->M_AXLELOADCAT_k,   7)   &&
        UpperBitsNotSet64(p->M_VOLTAGE_k,       4)   &&
        UpperBitsNotSet64(p->NID_CTRACTION_k,   10))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

