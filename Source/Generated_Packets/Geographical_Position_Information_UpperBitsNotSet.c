
#include "Geographical_Position_Information_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"
#include "Geographical_Position_Information_Core_1_UpperBitsNotSet.h"

int Geographical_Position_Information_UpperBitsNotSet(const Geographical_Position_Information_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->Q_NEWCOUNTRY,      1) ;
    if (p->Q_NEWCOUNTRY == 1)
    {
    status = status && UpperBitsNotSet64(p->NID_C,             10);
    }
    status = status && UpperBitsNotSet64(p->NID_BG,            14);
    status = status && UpperBitsNotSet64(p->D_POSOFF,          15);
    status = status && UpperBitsNotSet64(p->Q_MPOSITION,       1) ;
    status = status && UpperBitsNotSet64(p->M_POSITION,        24);
    status = status && UpperBitsNotSet64(p->N_ITER_1,          5) ;
    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        status = status && Geographical_Position_Information_Core_1_UpperBitsNotSet(&(p->sub_1[i]));
    }

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

