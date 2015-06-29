
#include "Staff_Responsible_distance_Information_from_loop_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"
#include "Staff_Responsible_distance_Information_from_loop_Core_1_UpperBitsNotSet.h"

int Staff_Responsible_distance_Information_from_loop_UpperBitsNotSet(const Staff_Responsible_distance_Information_from_loop_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->Q_NEWCOUNTRY_0,    1) ;
    if (p->Q_NEWCOUNTRY_0 == 1)
    {
    status = status && UpperBitsNotSet64(p->NID_C_0,           10);
    }
    status = status && UpperBitsNotSet64(p->NID_BG_0,          14);
    status = status && UpperBitsNotSet64(p->Q_NEWCOUNTRY_1,    1) ;
    if (p->Q_NEWCOUNTRY_1 == 1)
    {
    status = status && UpperBitsNotSet64(p->NID_C_1,           10);
    }
    status = status && UpperBitsNotSet64(p->NID_BG_1,          14);
    status = status && UpperBitsNotSet64(p->D_SR,              15);
    status = status && UpperBitsNotSet64(p->N_ITER_1,          5) ;
    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        status = status && Staff_Responsible_distance_Information_from_loop_Core_1_UpperBitsNotSet(&(p->sub_1[i]));
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

