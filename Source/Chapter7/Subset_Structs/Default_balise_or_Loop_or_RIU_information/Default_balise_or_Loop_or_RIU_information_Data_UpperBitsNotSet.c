
#include "Default_balise_or_Loop_or_RIU_information_Data_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Default_balise_or_Loop_or_RIU_information_Data_UpperBitsNotSet(const Default_balise_or_Loop_or_RIU_information_Data* p)
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

