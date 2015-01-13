
#ifndef LEVEL_CROSSING_INFORMATION_INIT_H_INCLUDED
#define LEVEL_CROSSING_INFORMATION_INIT_H_INCLUDED

#include "Level_Crossing_information.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void Level_Crossing_information_Init(Level_Crossing_information* p);


#endif // LEVEL_CROSSING_INFORMATION_INIT_H_INCLUDED

