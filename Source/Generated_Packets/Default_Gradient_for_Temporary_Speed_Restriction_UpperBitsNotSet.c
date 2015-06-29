
#include "Default_Gradient_for_Temporary_Speed_Restriction_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Default_Gradient_for_Temporary_Speed_Restriction_UpperBitsNotSet(const Default_Gradient_for_Temporary_Speed_Restriction_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_GDIR,            1) ;
    status = status && UpperBitsNotSet64(p->G_TSR,             8) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

