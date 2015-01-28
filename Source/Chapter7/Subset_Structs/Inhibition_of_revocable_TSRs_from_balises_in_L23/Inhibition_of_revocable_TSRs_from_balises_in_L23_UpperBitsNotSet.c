
#include "Inhibition_of_revocable_TSRs_from_balises_in_L23_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Inhibition_of_revocable_TSRs_from_balises_in_L23_UpperBitsNotSet(const Inhibition_of_revocable_TSRs_from_balises_in_L23* p)
{
    if (UpperBitsNotSet64(p->NID_PACKET,        8)   &&
        UpperBitsNotSet64(p->Q_DIR,             2)   &&
        UpperBitsNotSet64(p->L_PACKET,          13))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

