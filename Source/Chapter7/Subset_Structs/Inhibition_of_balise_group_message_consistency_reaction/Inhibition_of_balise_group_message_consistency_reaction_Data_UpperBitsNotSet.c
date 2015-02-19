
#include "Inhibition_of_balise_group_message_consistency_reaction_Data_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Inhibition_of_balise_group_message_consistency_reaction_Data_UpperBitsNotSet(const Inhibition_of_balise_group_message_consistency_reaction_Data* p)
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

