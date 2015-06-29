
#include "Route_Suitability_Data_Core_1_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Route_Suitability_Data_Core_1_UpperBitsNotSet(const Route_Suitability_Data_Core_1* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->D_SUITABILITY_k,   15);
    status = status && UpperBitsNotSet64(p->Q_SUITABILITY_k,   2) ;
    if (p->Q_SUITABILITY_k == 0)
    {
    status = status && UpperBitsNotSet64(p->M_LINEGAUGE_k,     8) ;
    }
    if (p->Q_SUITABILITY_k == 1)
    {
    status = status && UpperBitsNotSet64(p->M_AXLELOADCAT_k,   7) ;
    }
    if (p->Q_SUITABILITY_k == 2)
    {
    status = status && UpperBitsNotSet64(p->M_VOLTAGE_k,       4) ;
    }
    if ((p->Q_SUITABILITY_k == 2) && (p->M_VOLTAGE_k != 0))
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

