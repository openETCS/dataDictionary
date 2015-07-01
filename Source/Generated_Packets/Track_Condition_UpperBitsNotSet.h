
#ifndef TRACK_CONDITION_UPPERBITSNOTSET_H_INCLUDED
#define TRACK_CONDITION_UPPERBITSNOTSET_H_INCLUDED

#include "Track_Condition_Core.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Track_Condition_UpperBitsNotSet(const Track_Condition_Core* p);

#endif // TRACK_CONDITION_UPPERBITSNOTSET_H_INCLUDED

