
#ifndef INTERNATIONAL_STATIC_SPEED_PROFILE_UPPERBITSNOTSET_H_INCLUDED
#define INTERNATIONAL_STATIC_SPEED_PROFILE_UPPERBITSNOTSET_H_INCLUDED

#include "Adhesion_Factor.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int International_Static_Speed_Profile_UpperBitsNotSet(const International_Static_Speed_Profile* p);

#endif // INTERNATIONAL_STATIC_SPEED_PROFILE_UPPERBITSNOTSET_H_INCLUDED

