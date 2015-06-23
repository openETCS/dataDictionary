
#ifndef AXLE_LOAD_SPEED_PROFILE_CORE_2_1_UPPERBITSNOTSET_H_INCLUDED
#define AXLE_LOAD_SPEED_PROFILE_CORE_2_1_UPPERBITSNOTSET_H_INCLUDED

#include "Axle_Load_Speed_Profile_Core_2_1.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Axle_Load_Speed_Profile_Core_2_1_UpperBitsNotSet(const Axle_Load_Speed_Profile_Core_2_1* p);

#endif // AXLE_LOAD_SPEED_PROFILE_CORE_2_1_UPPERBITSNOTSET_H_INCLUDED

