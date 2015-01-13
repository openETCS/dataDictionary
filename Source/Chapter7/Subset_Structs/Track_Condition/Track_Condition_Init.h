
#ifndef TRACK_CONDITION_INIT_H_INCLUDED
#define TRACK_CONDITION_INIT_H_INCLUDED

#include "Track_Condition.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void Track_Condition_Init(Track_Condition* p);


#endif // TRACK_CONDITION_INIT_H_INCLUDED

