
#include "Linking_Core_1_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Linking_Core_1_UpperBitsNotSet(const Linking_Core_1* p)
{
    if (UpperBitsNotSet64(p->D_LINK_k,          15)  &&
        UpperBitsNotSet64(p->Q_NEWCOUNTRY_k,    1)   &&
        UpperBitsNotSet64(p->NID_C_k,           10)  &&
        UpperBitsNotSet64(p->NID_BG_k,          14)  &&
        UpperBitsNotSet64(p->Q_LINKORIENTATION_k, 1)   &&
        UpperBitsNotSet64(p->Q_LINKREACTION_k,  2)   &&
        UpperBitsNotSet64(p->Q_LOCACC_k,        6))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

