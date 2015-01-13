
#include "Position_Report_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Position_Report_UpperBitsNotSet(const Position_Report* p)
{
    if (UpperBitsNotSet64(p->NID_PACKET,        8)   &&
        UpperBitsNotSet64(p->L_PACKET,          13)  &&
        UpperBitsNotSet64(p->Q_SCALE,           2)   &&
        UpperBitsNotSet64(p->NID_LRBG,          24)  &&
        UpperBitsNotSet64(p->D_LRBG,            15)  &&
        UpperBitsNotSet64(p->Q_DIRLRBG,         2)   &&
        UpperBitsNotSet64(p->Q_DLRBG,           2)   &&
        UpperBitsNotSet64(p->L_DOUBTOVER,       15)  &&
        UpperBitsNotSet64(p->L_DOUBTUNDER,      15)  &&
        UpperBitsNotSet64(p->Q_LENGTH,          2)   &&
        UpperBitsNotSet64(p->L_TRAININT,        15)  &&
        UpperBitsNotSet64(p->V_TRAIN,           7)   &&
        UpperBitsNotSet64(p->Q_DIRTRAIN,        2)   &&
        UpperBitsNotSet64(p->M_MODE,            4)   &&
        UpperBitsNotSet64(p->M_LEVEL,           3)   &&
        UpperBitsNotSet64(p->NID_NTC,           8))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

