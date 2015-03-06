
#ifndef INHIBITION_OF_BALISE_GROUP_MESSAGE_CONSISTENCY_REACTION_INIT_H_INCLUDED
#define INHIBITION_OF_BALISE_GROUP_MESSAGE_CONSISTENCY_REACTION_INIT_H_INCLUDED

#include "Inhibition_of_balise_group_message_consistency_reaction.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void Inhibition_of_balise_group_message_consistency_reaction_Init(Inhibition_of_balise_group_message_consistency_reaction* p);


#endif // INHIBITION_OF_BALISE_GROUP_MESSAGE_CONSISTENCY_REACTION_INIT_H_INCLUDED

