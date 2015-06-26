
#include "International_Static_Speed_Profile_Core_1_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int International_Static_Speed_Profile_Core_1_UpperBitsNotSet(const International_Static_Speed_Profile_Core_1* p)
{
    if (UpperBitsNotSet64(p->Q_DIFF_n,          2)   &&
        UpperBitsNotSet64(p->NC_CDDIFF_n,       4)   &&
        UpperBitsNotSet64(p->NC_DIFF_n,         4)   &&
        UpperBitsNotSet64(p->V_DIFF_n,          7))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

