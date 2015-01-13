
#ifndef INTERNATIONAL_STATIC_SPEED_PROFILE_INIT_H_INCLUDED
#define INTERNATIONAL_STATIC_SPEED_PROFILE_INIT_H_INCLUDED

#include "International_Static_Speed_Profile.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void International_Static_Speed_Profile_Init(International_Static_Speed_Profile* p);


#endif // INTERNATIONAL_STATIC_SPEED_PROFILE_INIT_H_INCLUDED

