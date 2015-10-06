
#include "Default_balise_or_Loop_or_RIU_information_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Default_balise_or_Loop_or_RIU_information_UpperBitsNotSet(const Default_balise_or_Loop_or_RIU_information* p)
{
    if (UpperBitsNotSet64(p->Q_DIR,             2)   &&
        UpperBitsNotSet64(p->L_PACKET,          13))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

