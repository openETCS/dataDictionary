
#include "Level_Transition_Order_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"
#include "Level_Transition_Order_Core_1_UpperBitsNotSet.h"

int Level_Transition_Order_UpperBitsNotSet(const Level_Transition_Order_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->D_LEVELTR,         15);
    status = status && UpperBitsNotSet64(p->M_LEVELTR,         3) ;
    if (p->M_LEVELTR == 1)
    {
    status = status && UpperBitsNotSet64(p->NID_NTC,           8) ;
    }
    status = status && UpperBitsNotSet64(p->L_ACKLEVELTR,      15);
    status = status && UpperBitsNotSet64(p->N_ITER_1,          5) ;
    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        status = status && Level_Transition_Order_Core_1_UpperBitsNotSet(&(p->sub_1[i]));
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

