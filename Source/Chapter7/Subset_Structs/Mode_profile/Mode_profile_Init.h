
#ifndef MODE_PROFILE_INIT_H_INCLUDED
#define MODE_PROFILE_INIT_H_INCLUDED

#include "Mode_profile.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void Mode_profile_Init(Mode_profile* p);


#endif // MODE_PROFILE_INIT_H_INCLUDED

