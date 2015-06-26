
#include "Staff_Responsible_distance_Information_from_loop_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Staff_Responsible_distance_Information_from_loop_UpperBitsNotSet(const Staff_Responsible_distance_Information_from_loop_Core* p)
{
    if (UpperBitsNotSet64(p->Q_DIR,             2)   &&
        UpperBitsNotSet64(p->L_PACKET,          13)  &&
        UpperBitsNotSet64(p->Q_SCALE,           2)   &&
        UpperBitsNotSet64(p->Q_NEWCOUNTRY_0,    1)   &&
        UpperBitsNotSet64(p->NID_C_0,           10)  &&
        UpperBitsNotSet64(p->NID_BG_0,          14)  &&
        UpperBitsNotSet64(p->Q_NEWCOUNTRY_1,    1)   &&
        UpperBitsNotSet64(p->NID_C_1,           10)  &&
        UpperBitsNotSet64(p->NID_BG_1,          14)  &&
        UpperBitsNotSet64(p->D_SR,              15)  &&
        UpperBitsNotSet64(p->N_ITER_1,          5))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

