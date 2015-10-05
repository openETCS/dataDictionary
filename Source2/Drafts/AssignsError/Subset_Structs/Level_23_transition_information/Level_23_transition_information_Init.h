
#ifndef LEVEL_23_TRANSITION_INFORMATION_INIT_H_INCLUDED
#define LEVEL_23_TRANSITION_INFORMATION_INIT_H_INCLUDED

#include "Level_23_transition_information.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void Level_23_transition_information_Init(Level_23_transition_information* p);


#endif // LEVEL_23_TRANSITION_INFORMATION_INIT_H_INCLUDED

