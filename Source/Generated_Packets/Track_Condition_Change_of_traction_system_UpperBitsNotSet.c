
#include "Track_Condition_Change_of_traction_system_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Track_Condition_Change_of_traction_system_UpperBitsNotSet(const Track_Condition_Change_of_traction_system_Core* p)
{
    if (UpperBitsNotSet64(p->Q_DIR,             2)   &&
        UpperBitsNotSet64(p->L_PACKET,          13)  &&
        UpperBitsNotSet64(p->Q_SCALE,           2)   &&
        UpperBitsNotSet64(p->D_TRACTION,        15)  &&
        UpperBitsNotSet64(p->M_VOLTAGE,         4))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

