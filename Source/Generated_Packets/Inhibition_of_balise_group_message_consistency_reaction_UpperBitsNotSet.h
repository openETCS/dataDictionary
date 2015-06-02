
#ifndef INHIBITION_OF_BALISE_GROUP_MESSAGE_CONSISTENCY_REACTION_UPPERBITSNOTSET_H_INCLUDED
#define INHIBITION_OF_BALISE_GROUP_MESSAGE_CONSISTENCY_REACTION_UPPERBITSNOTSET_H_INCLUDED

#include "Inhibition_of_balise_group_message_consistency_reaction_Core.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Inhibition_of_balise_group_message_consistency_reaction_UpperBitsNotSet(const Inhibition_of_balise_group_message_consistency_reaction_Core* p);

#endif // INHIBITION_OF_BALISE_GROUP_MESSAGE_CONSISTENCY_REACTION_UPPERBITSNOTSET_H_INCLUDED

