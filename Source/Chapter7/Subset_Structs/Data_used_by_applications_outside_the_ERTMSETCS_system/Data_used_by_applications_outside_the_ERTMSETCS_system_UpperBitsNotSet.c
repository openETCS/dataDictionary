
#include "Data_used_by_applications_outside_the_ERTMSETCS_system_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Data_used_by_applications_outside_the_ERTMSETCS_system_UpperBitsNotSet(const Data_used_by_applications_outside_the_ERTMSETCS_system* p)
{
    if (UpperBitsNotSet64(p->NID_PACKET,        8)   &&
        UpperBitsNotSet64(p->Q_DIR,             2)   &&
        UpperBitsNotSet64(p->L_PACKET,          13)  &&
        UpperBitsNotSet64(p->NID_XUSER,         9)   &&
        UpperBitsNotSet64(p->NID_NTC,           8)   &&
        UpperBitsNotSet64(p->Other_data_depending_on__NID_XUSER, ))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

