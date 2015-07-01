
#include "Position_Report_based_on_two_balise_groups_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Position_Report_based_on_two_balise_groups_UpperBitsNotSet(const Position_Report_based_on_two_balise_groups_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->NID_LRBG,          24);
    status = status && UpperBitsNotSet64(p->NID_PRVLRBG,       24);
    status = status && UpperBitsNotSet64(p->D_LRBG,            15);
    status = status && UpperBitsNotSet64(p->Q_DIRLRBG,         2) ;
    status = status && UpperBitsNotSet64(p->Q_DLRBG,           2) ;
    status = status && UpperBitsNotSet64(p->L_DOUBTOVER,       15);
    status = status && UpperBitsNotSet64(p->L_DOUBTUNDER,      15);
    status = status && UpperBitsNotSet64(p->Q_LENGTH,          2) ;
    if ((p->Q_LENGTH == 1) || (p->Q_LENGTH == 2))
    {
    status = status && UpperBitsNotSet64(p->L_TRAININT,        15);
    }
    status = status && UpperBitsNotSet64(p->V_TRAIN,           7) ;
    status = status && UpperBitsNotSet64(p->Q_DIRTRAIN,        2) ;
    status = status && UpperBitsNotSet64(p->M_MODE,            4) ;
    status = status && UpperBitsNotSet64(p->M_LEVEL,           3) ;
    if (p->M_LEVEL == 1)
    {
    status = status && UpperBitsNotSet64(p->NID_NTC,           8) ;
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

