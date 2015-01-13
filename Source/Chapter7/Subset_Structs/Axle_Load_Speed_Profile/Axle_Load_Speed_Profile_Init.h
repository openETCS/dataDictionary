
#ifndef AXLE_LOAD_SPEED_PROFILE_INIT_H_INCLUDED
#define AXLE_LOAD_SPEED_PROFILE_INIT_H_INCLUDED

#include "Axle_Load_Speed_Profile.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void Axle_Load_Speed_Profile_Init(Axle_Load_Speed_Profile* p);


#endif // AXLE_LOAD_SPEED_PROFILE_INIT_H_INCLUDED

