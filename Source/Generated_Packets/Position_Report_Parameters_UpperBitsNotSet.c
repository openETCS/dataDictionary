
#include "Position_Report_Parameters_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Position_Report_Parameters_UpperBitsNotSet(const Position_Report_Parameters_Core* p)
{
    if (UpperBitsNotSet64(p->Q_DIR,             2)   &&
        UpperBitsNotSet64(p->L_PACKET,          13)  &&
        UpperBitsNotSet64(p->Q_SCALE,           2)   &&
        UpperBitsNotSet64(p->T_CYCLOC,          8)   &&
        UpperBitsNotSet64(p->D_CYCLOC,          15)  &&
        UpperBitsNotSet64(p->M_LOC,             3)   &&
        UpperBitsNotSet64(p->N_ITER_1,          5))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

