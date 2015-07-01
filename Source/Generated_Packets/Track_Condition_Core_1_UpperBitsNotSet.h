
#ifndef TRACK_CONDITION_CORE_1_UPPERBITSNOTSET_H_INCLUDED
#define TRACK_CONDITION_CORE_1_UPPERBITSNOTSET_H_INCLUDED

#include "Track_Condition_Core_1.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Track_Condition_Core_1_UpperBitsNotSet(const Track_Condition_Core_1* p);

#endif // TRACK_CONDITION_CORE_1_UPPERBITSNOTSET_H_INCLUDED

