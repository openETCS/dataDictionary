
#include "Track_Condition_Change_of_allowed_current_consumption_Data_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Track_Condition_Change_of_allowed_current_consumption_Data_UpperBitsNotSet(const Track_Condition_Change_of_allowed_current_consumption_Data* p)
{
    if (UpperBitsNotSet64(p->Q_DIR,             2)   &&
        UpperBitsNotSet64(p->Q_SCALE,           2)   &&
        UpperBitsNotSet64(p->D_CURRENT,         15)  &&
        UpperBitsNotSet64(p->M_CURRENT,         10))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

