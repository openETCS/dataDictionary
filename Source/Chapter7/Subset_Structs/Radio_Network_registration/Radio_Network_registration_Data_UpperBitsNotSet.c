
#include "Radio_Network_registration_Data_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Radio_Network_registration_Data_UpperBitsNotSet(const Radio_Network_registration_Data* p)
{
    if (UpperBitsNotSet64(p->Q_DIR,             2)   &&
        UpperBitsNotSet64(p->NID_MN,            24))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

