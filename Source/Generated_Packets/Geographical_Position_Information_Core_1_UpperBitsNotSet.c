
#include "Geographical_Position_Information_Core_1_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Geographical_Position_Information_Core_1_UpperBitsNotSet(const Geographical_Position_Information_Core_1* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_NEWCOUNTRY_k,    1) ;
    if (p->Q_NEWCOUNTRY_k == 1)
    {
    status = status && UpperBitsNotSet64(p->NID_C_k,           10);
    }
    status = status && UpperBitsNotSet64(p->NID_BG_k,          14);
    status = status && UpperBitsNotSet64(p->D_POSOFF_k,        15);
    status = status && UpperBitsNotSet64(p->Q_MPOSITION_k,     1) ;
    status = status && UpperBitsNotSet64(p->M_POSITION_k,      24);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

