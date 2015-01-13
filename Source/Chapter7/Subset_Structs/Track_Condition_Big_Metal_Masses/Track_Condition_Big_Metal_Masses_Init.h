
#ifndef TRACK_CONDITION_BIG_METAL_MASSES_INIT_H_INCLUDED
#define TRACK_CONDITION_BIG_METAL_MASSES_INIT_H_INCLUDED

#include "Track_Condition_Big_Metal_Masses.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void Track_Condition_Big_Metal_Masses_Init(Track_Condition_Big_Metal_Masses* p);


#endif // TRACK_CONDITION_BIG_METAL_MASSES_INIT_H_INCLUDED

