
#include "EOLM_Packet_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int EOLM_Packet_UpperBitsNotSet(const EOLM_Packet_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->NID_LOOP,          14);
    status = status && UpperBitsNotSet64(p->D_LOOP,            15);
    status = status && UpperBitsNotSet64(p->L_LOOP,            15);
    status = status && UpperBitsNotSet64(p->Q_LOOPDIR,         1) ;
    status = status && UpperBitsNotSet64(p->Q_SSCODE,          4) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

