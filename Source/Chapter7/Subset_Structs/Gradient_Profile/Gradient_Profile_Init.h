
#ifndef GRADIENT_PROFILE_INIT_H_INCLUDED
#define GRADIENT_PROFILE_INIT_H_INCLUDED

#include "Gradient_Profile.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void Gradient_Profile_Init(Gradient_Profile* p);


#endif // GRADIENT_PROFILE_INIT_H_INCLUDED

