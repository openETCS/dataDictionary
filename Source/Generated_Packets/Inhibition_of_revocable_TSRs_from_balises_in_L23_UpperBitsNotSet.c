
#include "Inhibition_of_revocable_TSRs_from_balises_in_L23_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Inhibition_of_revocable_TSRs_from_balises_in_L23_UpperBitsNotSet(const Inhibition_of_revocable_TSRs_from_balises_in_L23_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

