
#ifndef TRACK_CONDITION_CHANGE_OF_TRACTION_SYSTEM_INIT_H_INCLUDED
#define TRACK_CONDITION_CHANGE_OF_TRACTION_SYSTEM_INIT_H_INCLUDED

#include "Track_Condition_Change_of_traction_system.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void Track_Condition_Change_of_traction_system_Init(Track_Condition_Change_of_traction_system* p);


#endif // TRACK_CONDITION_CHANGE_OF_TRACTION_SYSTEM_INIT_H_INCLUDED

