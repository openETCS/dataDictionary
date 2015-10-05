
#ifndef DANGER_FOR_SHUNTING_INFORMATION_INIT_H_INCLUDED
#define DANGER_FOR_SHUNTING_INFORMATION_INIT_H_INCLUDED

#include "Danger_for_Shunting_information.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void Danger_for_Shunting_information_Init(Danger_for_Shunting_information* p);


#endif // DANGER_FOR_SHUNTING_INFORMATION_INIT_H_INCLUDED

