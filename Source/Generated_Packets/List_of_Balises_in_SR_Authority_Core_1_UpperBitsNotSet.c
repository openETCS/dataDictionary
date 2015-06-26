
#include "List_of_Balises_in_SR_Authority_Core_1_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int List_of_Balises_in_SR_Authority_Core_1_UpperBitsNotSet(const List_of_Balises_in_SR_Authority_Core_1* p)
{
    if (UpperBitsNotSet64(p->Q_NEWCOUNTRY_k,    1)   &&
        UpperBitsNotSet64(p->NID_C_k,           10)  &&
        UpperBitsNotSet64(p->NID_BG_k,          14))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

