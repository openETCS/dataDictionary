
#include "System_Version_order_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int System_Version_order_UpperBitsNotSet(const System_Version_order_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->M_VERSION,         7) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

