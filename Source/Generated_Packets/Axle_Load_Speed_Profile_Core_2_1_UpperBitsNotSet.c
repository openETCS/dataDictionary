
#include "Axle_Load_Speed_Profile_Core_2_1_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Axle_Load_Speed_Profile_Core_2_1_UpperBitsNotSet(const Axle_Load_Speed_Profile_Core_2_1* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->M_AXLELOADCAT_k_m, 7) ;
    status = status && UpperBitsNotSet64(p->V_AXLELOAD_k_m,    7) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

