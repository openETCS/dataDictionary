
#include "Position_Report_Parameters_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"
#include "Position_Report_Parameters_Core_1_UpperBitsNotSet.h"

int Position_Report_Parameters_UpperBitsNotSet(const Position_Report_Parameters_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->T_CYCLOC,          8) ;
    status = status && UpperBitsNotSet64(p->D_CYCLOC,          15);
    status = status && UpperBitsNotSet64(p->M_LOC,             3) ;
    status = status && UpperBitsNotSet64(p->N_ITER_1,          5) ;
    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        status = status && Position_Report_Parameters_Core_1_UpperBitsNotSet(&(p->sub_1[i]));
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

