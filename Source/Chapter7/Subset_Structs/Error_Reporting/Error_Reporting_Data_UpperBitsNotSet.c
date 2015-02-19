
#include "Error_Reporting_Data_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Error_Reporting_Data_UpperBitsNotSet(const Error_Reporting_Data* p)
{
    if (UpperBitsNotSet64(p->M_ERROR,           8))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

