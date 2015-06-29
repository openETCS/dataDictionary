
#include "List_of_balises_for_SH_Area_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"
#include "List_of_balises_for_SH_Area_Core_1_UpperBitsNotSet.h"

int List_of_balises_for_SH_Area_UpperBitsNotSet(const List_of_balises_for_SH_Area_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->N_ITER_1,          5) ;
    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        status = status && List_of_balises_for_SH_Area_Core_1_UpperBitsNotSet(&(p->sub_1[i]));
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

