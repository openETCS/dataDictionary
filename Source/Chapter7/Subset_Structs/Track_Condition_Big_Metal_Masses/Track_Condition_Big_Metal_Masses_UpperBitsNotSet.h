
#ifndef TRACK_CONDITION_BIG_METAL_MASSES_UPPERBITSNOTSET_H_INCLUDED
#define TRACK_CONDITION_BIG_METAL_MASSES_UPPERBITSNOTSET_H_INCLUDED

#include "Adhesion_Factor.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Track_Condition_Big_Metal_Masses_UpperBitsNotSet(const Track_Condition_Big_Metal_Masses* p);

#endif // TRACK_CONDITION_BIG_METAL_MASSES_UPPERBITSNOTSET_H_INCLUDED

