
#include "Staff_Responsible_distance_Information_from_loop_Core_1_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Staff_Responsible_distance_Information_from_loop_Core_1_UpperBitsNotSet(const Staff_Responsible_distance_Information_from_loop_Core_1* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_NEWCOUNTRY_k,    1) ;
    if (p->Q_NEWCOUNTRY_k == 1)
    {
    status = status && UpperBitsNotSet64(p->NID_C_k,           10);
    }
    status = status && UpperBitsNotSet64(p->NID_BG_k,          14);
    status = status && UpperBitsNotSet64(p->D_SR_k,            15);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

