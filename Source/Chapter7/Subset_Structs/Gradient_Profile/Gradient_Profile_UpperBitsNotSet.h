
#ifndef GRADIENT_PROFILE_UPPERBITSNOTSET_H_INCLUDED
#define GRADIENT_PROFILE_UPPERBITSNOTSET_H_INCLUDED

#include "Adhesion_Factor.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Gradient_Profile_UpperBitsNotSet(const Gradient_Profile* p);

#endif // GRADIENT_PROFILE_UPPERBITSNOTSET_H_INCLUDED

