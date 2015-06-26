
#include "Route_Suitability_Data_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Route_Suitability_Data_UpperBitsNotSet(const Route_Suitability_Data_Core* p)
{
    if (UpperBitsNotSet64(p->Q_DIR,             2)   &&
        UpperBitsNotSet64(p->L_PACKET,          13)  &&
        UpperBitsNotSet64(p->Q_SCALE,           2)   &&
        UpperBitsNotSet64(p->Q_TRACKINIT,       1)   &&
        UpperBitsNotSet64(p->D_TRACKINIT,       15)  &&
        UpperBitsNotSet64(p->D_SUITABILITY,     15)  &&
        UpperBitsNotSet64(p->Q_SUITABILITY,     2)   &&
        UpperBitsNotSet64(p->M_LINEGAUGE,       8)   &&
        UpperBitsNotSet64(p->M_AXLELOADCAT,     7)   &&
        UpperBitsNotSet64(p->M_VOLTAGE,         4)   &&
        UpperBitsNotSet64(p->NID_CTRACTION,     10)  &&
        UpperBitsNotSet64(p->N_ITER_1,          5))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

