
#ifndef STOP_SHUNTING_ON_DESK_OPENING_DATA_INIT_H_INCLUDED
#define STOP_SHUNTING_ON_DESK_OPENING_DATA_INIT_H_INCLUDED

#include "Stop_Shunting_on_desk_opening_Data.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void Stop_Shunting_on_desk_opening_Data_Init(Stop_Shunting_on_desk_opening_Data* p);


#endif // STOP_SHUNTING_ON_DESK_OPENING_DATA_INIT_H_INCLUDED

