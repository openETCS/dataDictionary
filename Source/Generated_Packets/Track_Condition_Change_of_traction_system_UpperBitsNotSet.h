
#ifndef TRACK_CONDITION_CHANGE_OF_TRACTION_SYSTEM_UPPERBITSNOTSET_H_INCLUDED
#define TRACK_CONDITION_CHANGE_OF_TRACTION_SYSTEM_UPPERBITSNOTSET_H_INCLUDED

#include "Track_Condition_Change_of_traction_system_Core.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Track_Condition_Change_of_traction_system_UpperBitsNotSet(const Track_Condition_Change_of_traction_system_Core* p);

#endif // TRACK_CONDITION_CHANGE_OF_TRACTION_SYSTEM_UPPERBITSNOTSET_H_INCLUDED

