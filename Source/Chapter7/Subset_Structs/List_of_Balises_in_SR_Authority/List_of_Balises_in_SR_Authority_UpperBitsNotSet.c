
#include "List_of_Balises_in_SR_Authority_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int List_of_Balises_in_SR_Authority_UpperBitsNotSet(const List_of_Balises_in_SR_Authority* p)
{
    if (UpperBitsNotSet64(p->NID_PACKET,        8)   &&
        UpperBitsNotSet64(p->Q_DIR,             2)   &&
        UpperBitsNotSet64(p->L_PACKET,          13)  &&
        UpperBitsNotSet64(p->N_ITER,            5)   &&
        UpperBitsNotSet64(p->Q_NEWCOUNTRY(k),   1)   &&
        UpperBitsNotSet64(p->NID_C(k),          10)  &&
        UpperBitsNotSet64(p->NID_BG(k),         14))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

