
#ifndef PERMITTED_BRAKING_DISTANCE_INFORMATION_UPPERBITSNOTSET_H_INCLUDED
#define PERMITTED_BRAKING_DISTANCE_INFORMATION_UPPERBITSNOTSET_H_INCLUDED

#include "Permitted_Braking_Distance_Information_Core.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Permitted_Braking_Distance_Information_UpperBitsNotSet(const Permitted_Braking_Distance_Information_Core* p);

#endif // PERMITTED_BRAKING_DISTANCE_INFORMATION_UPPERBITSNOTSET_H_INCLUDED

