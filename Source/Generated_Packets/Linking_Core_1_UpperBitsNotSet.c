
#include "Linking_Core_1_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Linking_Core_1_UpperBitsNotSet(const Linking_Core_1* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->D_LINK_k,          15);
    status = status && UpperBitsNotSet64(p->Q_NEWCOUNTRY_k,    1) ;
    if (p->Q_NEWCOUNTRY_k == 1)
    {
    status = status && UpperBitsNotSet64(p->NID_C_k,           10);
    }
    status = status && UpperBitsNotSet64(p->NID_BG_k,          14);
    status = status && UpperBitsNotSet64(p->Q_LINKORIENTATION_k, 1) ;
    status = status && UpperBitsNotSet64(p->Q_LINKREACTION_k,  2) ;
    status = status && UpperBitsNotSet64(p->Q_LOCACC_k,        6) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

