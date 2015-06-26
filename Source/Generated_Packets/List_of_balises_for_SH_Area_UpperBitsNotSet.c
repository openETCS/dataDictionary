
#include "List_of_balises_for_SH_Area_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int List_of_balises_for_SH_Area_UpperBitsNotSet(const List_of_balises_for_SH_Area_Core* p)
{
    if (UpperBitsNotSet64(p->Q_DIR,             2)   &&
        UpperBitsNotSet64(p->L_PACKET,          13)  &&
        UpperBitsNotSet64(p->N_ITER_1,          5))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

