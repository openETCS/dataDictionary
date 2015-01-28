
#include "Error_Reporting_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Error_Reporting_UpperBitsNotSet(const Error_Reporting* p)
{
    if (UpperBitsNotSet64(p->NID_PACKET,        8)   &&
        UpperBitsNotSet64(p->L_PACKET,          13)  &&
        UpperBitsNotSet64(p->M_ERROR,           8))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

