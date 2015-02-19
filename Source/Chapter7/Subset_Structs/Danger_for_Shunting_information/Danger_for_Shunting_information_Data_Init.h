
#ifndef DANGER_FOR_SHUNTING_INFORMATION_DATA_INIT_H_INCLUDED
#define DANGER_FOR_SHUNTING_INFORMATION_DATA_INIT_H_INCLUDED

#include "Danger_for_Shunting_information_Data.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void Danger_for_Shunting_information_Data_Init(Danger_for_Shunting_information_Data* p);


#endif // DANGER_FOR_SHUNTING_INFORMATION_DATA_INIT_H_INCLUDED

