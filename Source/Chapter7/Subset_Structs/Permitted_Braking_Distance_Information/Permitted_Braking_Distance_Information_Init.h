
#ifndef PERMITTED_BRAKING_DISTANCE_INFORMATION_INIT_H_INCLUDED
#define PERMITTED_BRAKING_DISTANCE_INFORMATION_INIT_H_INCLUDED

#include "Permitted_Braking_Distance_Information.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void Permitted_Braking_Distance_Information_Init(Permitted_Braking_Distance_Information* p);


#endif // PERMITTED_BRAKING_DISTANCE_INFORMATION_INIT_H_INCLUDED

