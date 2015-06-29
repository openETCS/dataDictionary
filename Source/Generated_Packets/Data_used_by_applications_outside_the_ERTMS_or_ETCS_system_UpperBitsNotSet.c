
#include "Data_used_by_applications_outside_the_ERTMS_or_ETCS_system_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Data_used_by_applications_outside_the_ERTMS_or_ETCS_system_UpperBitsNotSet(const Data_used_by_applications_outside_the_ERTMS_or_ETCS_system_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->NID_XUSER,         9) ;
    status = status && UpperBitsNotSet64(p->Other_data_depending_on__NID_XUSER, 8) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

