
#include "Inhibition_of_balise_group_message_consistency_reaction_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Inhibition_of_balise_group_message_consistency_reaction_UpperBitsNotSet(const Inhibition_of_balise_group_message_consistency_reaction* p)
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

