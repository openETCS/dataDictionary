
#ifndef LEVEL_23_MOVEMENT_AUTHORITY_INIT_H_INCLUDED
#define LEVEL_23_MOVEMENT_AUTHORITY_INIT_H_INCLUDED

#include "Level_23_Movement_Authority.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void Level_23_Movement_Authority_Init(Level_23_Movement_Authority* p);


#endif // LEVEL_23_MOVEMENT_AUTHORITY_INIT_H_INCLUDED

