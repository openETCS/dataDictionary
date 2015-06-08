
#include "EOLM_Packet_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int EOLM_Packet_UpperBitsNotSet(const EOLM_Packet_Core* p)
{
    if (UpperBitsNotSet64(p->Q_DIR,             2)   &&
        UpperBitsNotSet64(p->L_PACKET,          13)  &&
        UpperBitsNotSet64(p->Q_SCALE,           2)   &&
        UpperBitsNotSet64(p->NID_LOOP,          14)  &&
        UpperBitsNotSet64(p->D_LOOP,            15)  &&
        UpperBitsNotSet64(p->L_LOOP,            15)  &&
        UpperBitsNotSet64(p->Q_LOOPDIR,         1)   &&
        UpperBitsNotSet64(p->Q_SSCODE,          4))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

