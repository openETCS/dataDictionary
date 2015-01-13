
#ifndef LEVEL_1_MOVEMENT_AUTHORITY_INIT_H_INCLUDED
#define LEVEL_1_MOVEMENT_AUTHORITY_INIT_H_INCLUDED

#include "Level_1_Movement_Authority.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void Level_1_Movement_Authority_Init(Level_1_Movement_Authority* p);


#endif // LEVEL_1_MOVEMENT_AUTHORITY_INIT_H_INCLUDED

