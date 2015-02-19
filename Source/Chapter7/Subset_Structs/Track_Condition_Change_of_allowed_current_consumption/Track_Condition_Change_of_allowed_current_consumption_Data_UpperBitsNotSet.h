
#ifndef TRACK_CONDITION_CHANGE_OF_ALLOWED_CURRENT_CONSUMPTION_DATA_UPPERBITSNOTSET_H_INCLUDED
#define TRACK_CONDITION_CHANGE_OF_ALLOWED_CURRENT_CONSUMPTION_DATA_UPPERBITSNOTSET_H_INCLUDED

#include "Track_Condition_Change_of_allowed_current_consumption_Data.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Track_Condition_Change_of_allowed_current_consumption_Data_UpperBitsNotSet(const Track_Condition_Change_of_allowed_current_consumption_Data* p);

#endif // TRACK_CONDITION_CHANGE_OF_ALLOWED_CURRENT_CONSUMPTION_DATA_UPPERBITSNOTSET_H_INCLUDED

