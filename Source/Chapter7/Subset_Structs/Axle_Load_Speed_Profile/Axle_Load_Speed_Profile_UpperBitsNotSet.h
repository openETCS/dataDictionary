
#ifndef AXLE_LOAD_SPEED_PROFILE_UPPERBITSNOTSET_H_INCLUDED
#define AXLE_LOAD_SPEED_PROFILE_UPPERBITSNOTSET_H_INCLUDED

#include "Adhesion_Factor.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Axle_Load_Speed_Profile_UpperBitsNotSet(const Axle_Load_Speed_Profile* p);

#endif // AXLE_LOAD_SPEED_PROFILE_UPPERBITSNOTSET_H_INCLUDED

