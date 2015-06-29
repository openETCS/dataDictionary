
#include "Adhesion_Factor_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Adhesion_Factor_UpperBitsNotSet(const Adhesion_Factor_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->D_ADHESION,        15);
    status = status && UpperBitsNotSet64(p->L_ADHESION,        15);
    status = status && UpperBitsNotSet64(p->M_ADHESION,        1) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

