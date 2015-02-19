
#ifndef TRACK_CONDITION_CHANGE_OF_ALLOWED_CURRENT_CONSUMPTION_DATA_INIT_H_INCLUDED
#define TRACK_CONDITION_CHANGE_OF_ALLOWED_CURRENT_CONSUMPTION_DATA_INIT_H_INCLUDED

#include "Track_Condition_Change_of_allowed_current_consumption_Data.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void Track_Condition_Change_of_allowed_current_consumption_Data_Init(Track_Condition_Change_of_allowed_current_consumption_Data* p);


#endif // TRACK_CONDITION_CHANGE_OF_ALLOWED_CURRENT_CONSUMPTION_DATA_INIT_H_INCLUDED

