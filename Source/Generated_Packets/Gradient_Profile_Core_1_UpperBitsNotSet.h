
#ifndef GRADIENT_PROFILE_CORE_1_UPPERBITSNOTSET_H_INCLUDED
#define GRADIENT_PROFILE_CORE_1_UPPERBITSNOTSET_H_INCLUDED

#include "Gradient_Profile_Core_1.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Gradient_Profile_Core_1_UpperBitsNotSet(const Gradient_Profile_Core_1* p);

#endif // GRADIENT_PROFILE_CORE_1_UPPERBITSNOTSET_H_INCLUDED

