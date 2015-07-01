
#include "Train_running_number_from_RBC_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Train_running_number_from_RBC_UpperBitsNotSet(const Train_running_number_from_RBC_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->NID_OPERATIONAL,   32);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

