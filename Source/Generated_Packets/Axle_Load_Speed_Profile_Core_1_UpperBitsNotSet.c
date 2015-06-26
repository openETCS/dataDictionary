
#include "Axle_Load_Speed_Profile_Core_1_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Axle_Load_Speed_Profile_Core_1_UpperBitsNotSet(const Axle_Load_Speed_Profile_Core_1* p)
{
    if (UpperBitsNotSet64(p->M_AXLELOADCAT_n,   7)   &&
        UpperBitsNotSet64(p->V_AXLELOAD_n,      7))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

