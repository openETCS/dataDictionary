
#include "Error_Reporting_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Error_Reporting_UpperBitsNotSet(const Error_Reporting_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->M_ERROR,           8) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

