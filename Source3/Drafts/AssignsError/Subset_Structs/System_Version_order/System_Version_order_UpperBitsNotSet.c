
#include "System_Version_order_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int System_Version_order_UpperBitsNotSet(const System_Version_order* p)
{
    if (UpperBitsNotSet64(p->Q_DIR,             2)   &&
        UpperBitsNotSet64(p->L_PACKET,          13)  &&
        UpperBitsNotSet64(p->M_VERSION,         7))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

