
#include "Permitted_Braking_Distance_Information_Core_1_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Permitted_Braking_Distance_Information_Core_1_UpperBitsNotSet(const Permitted_Braking_Distance_Information_Core_1* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->D_PBD_k,           15);
    status = status && UpperBitsNotSet64(p->Q_GDIR_k,          1) ;
    status = status && UpperBitsNotSet64(p->G_PBDSR_k,         8) ;
    status = status && UpperBitsNotSet64(p->Q_PBDSR_k,         1) ;
    status = status && UpperBitsNotSet64(p->D_PBDSR_k,         15);
    status = status && UpperBitsNotSet64(p->L_PBDSR_k,         15);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

