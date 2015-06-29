
#include "Route_Suitability_Data_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"
#include "Route_Suitability_Data_Core_1_UpperBitsNotSet.h"

int Route_Suitability_Data_UpperBitsNotSet(const Route_Suitability_Data_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->Q_TRACKINIT,       1) ;
    if (p->Q_TRACKINIT == 1)
    {
    status = status && UpperBitsNotSet64(p->D_TRACKINIT,       15);
    }
    if (p->Q_TRACKINIT == 0)
    {
    status = status && UpperBitsNotSet64(p->D_SUITABILITY,     15);
    status = status && UpperBitsNotSet64(p->Q_SUITABILITY,     2) ;
    if (p->Q_SUITABILITY == 0)
    {
    status = status && UpperBitsNotSet64(p->M_LINEGAUGE,       8) ;
    }
    if (p->Q_SUITABILITY == 1)
    {
    status = status && UpperBitsNotSet64(p->M_AXLELOADCAT,     7) ;
    }
    if (p->Q_SUITABILITY == 2)
    {
    status = status && UpperBitsNotSet64(p->M_VOLTAGE,         4) ;
    }
    if ((p->Q_SUITABILITY == 2) && (p->M_VOLTAGE != 0))
    {
    status = status && UpperBitsNotSet64(p->NID_CTRACTION,     10);
    }
    status = status && UpperBitsNotSet64(p->N_ITER_1,          5) ;
    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        status = status && Route_Suitability_Data_Core_1_UpperBitsNotSet(&(p->sub_1[i]));
    }
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

