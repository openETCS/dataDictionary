
#include "List_of_Balises_in_SR_Authority_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int List_of_Balises_in_SR_Authority_UpperBitsNotSet(const List_of_Balises_in_SR_Authority_Core* p)
{
    if (UpperBitsNotSet64(p->Q_DIR,             2)   &&
        UpperBitsNotSet64(p->L_PACKET,          13))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

