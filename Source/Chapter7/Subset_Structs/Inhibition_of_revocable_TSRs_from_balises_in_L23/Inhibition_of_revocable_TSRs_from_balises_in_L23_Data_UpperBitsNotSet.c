
#include "Inhibition_of_revocable_TSRs_from_balises_in_L23_Data_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Inhibition_of_revocable_TSRs_from_balises_in_L23_Data_UpperBitsNotSet(const Inhibition_of_revocable_TSRs_from_balises_in_L23_Data* p)
{
    if (UpperBitsNotSet64(p->Q_DIR,             2))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

