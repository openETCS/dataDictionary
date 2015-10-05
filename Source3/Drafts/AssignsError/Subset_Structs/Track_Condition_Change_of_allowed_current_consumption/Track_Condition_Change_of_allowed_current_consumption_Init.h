
#ifndef TRACK_CONDITION_CHANGE_OF_ALLOWED_CURRENT_CONSUMPTION_INIT_H_INCLUDED
#define TRACK_CONDITION_CHANGE_OF_ALLOWED_CURRENT_CONSUMPTION_INIT_H_INCLUDED

#include "Track_Condition_Change_of_allowed_current_consumption.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void Track_Condition_Change_of_allowed_current_consumption_Init(Track_Condition_Change_of_allowed_current_consumption* p);


#endif // TRACK_CONDITION_CHANGE_OF_ALLOWED_CURRENT_CONSUMPTION_INIT_H_INCLUDED

