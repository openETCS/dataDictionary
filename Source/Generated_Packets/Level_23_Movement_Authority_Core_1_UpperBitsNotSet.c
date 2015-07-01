
#include "Level_23_Movement_Authority_Core_1_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Level_23_Movement_Authority_Core_1_UpperBitsNotSet(const Level_23_Movement_Authority_Core_1* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->L_SECTION_k,       15);
    status = status && UpperBitsNotSet64(p->Q_SECTIONTIMER_k,  1) ;
    status = status && UpperBitsNotSet64(p->T_SECTIONTIMER_k,  10);
    status = status && UpperBitsNotSet64(p->D_SECTIONTIMERSTOPLOC_k, 15);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

