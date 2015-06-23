
#ifndef INTERNATIONAL_STATIC_SPEED_PROFILE_CORE_1_UPPERBITSNOTSET_H_INCLUDED
#define INTERNATIONAL_STATIC_SPEED_PROFILE_CORE_1_UPPERBITSNOTSET_H_INCLUDED

#include "International_Static_Speed_Profile_Core_1.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int International_Static_Speed_Profile_Core_1_UpperBitsNotSet(const International_Static_Speed_Profile_Core_1* p);

#endif // INTERNATIONAL_STATIC_SPEED_PROFILE_CORE_1_UPPERBITSNOTSET_H_INCLUDED

