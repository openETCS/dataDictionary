
#include "Position_Report_Parameters_Core_1_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Position_Report_Parameters_Core_1_UpperBitsNotSet(const Position_Report_Parameters_Core_1* p)
{
    if (UpperBitsNotSet64(p->D_LOC_k,           15)  &&
        UpperBitsNotSet64(p->Q_LGTLOC_k,        1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

