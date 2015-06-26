
#include "Level_1_Movement_Authority_Core_1_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Level_1_Movement_Authority_Core_1_UpperBitsNotSet(const Level_1_Movement_Authority_Core_1* p)
{
    if (UpperBitsNotSet64(p->L_SECTION_k,       15)  &&
        UpperBitsNotSet64(p->Q_SECTIONTIMER_k,  1)   &&
        UpperBitsNotSet64(p->T_SECTIONTIMER_k,  10)  &&
        UpperBitsNotSet64(p->D_SECTIONTIMERSTOPLOC_k, 15))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

