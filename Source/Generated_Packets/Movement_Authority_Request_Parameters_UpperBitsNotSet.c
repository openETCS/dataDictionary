
#include "Movement_Authority_Request_Parameters_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Movement_Authority_Request_Parameters_UpperBitsNotSet(const Movement_Authority_Request_Parameters_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->T_MAR,             8) ;
    status = status && UpperBitsNotSet64(p->T_TIMEOUTRQST,     10);
    status = status && UpperBitsNotSet64(p->T_CYCRQST,         8) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

