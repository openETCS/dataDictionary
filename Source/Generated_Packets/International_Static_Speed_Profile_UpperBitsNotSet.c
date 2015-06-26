
#include "International_Static_Speed_Profile_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int International_Static_Speed_Profile_UpperBitsNotSet(const International_Static_Speed_Profile_Core* p)
{
    if (UpperBitsNotSet64(p->Q_DIR,             2)   &&
        UpperBitsNotSet64(p->L_PACKET,          13)  &&
        UpperBitsNotSet64(p->Q_SCALE,           2)   &&
        UpperBitsNotSet64(p->D_STATIC,          15)  &&
        UpperBitsNotSet64(p->V_STATIC,          7)   &&
        UpperBitsNotSet64(p->Q_FRONT,           1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

