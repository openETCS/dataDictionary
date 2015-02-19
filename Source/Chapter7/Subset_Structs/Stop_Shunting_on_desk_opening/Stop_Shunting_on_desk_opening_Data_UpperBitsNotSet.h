
#ifndef STOP_SHUNTING_ON_DESK_OPENING_DATA_UPPERBITSNOTSET_H_INCLUDED
#define STOP_SHUNTING_ON_DESK_OPENING_DATA_UPPERBITSNOTSET_H_INCLUDED

#include "Stop_Shunting_on_desk_opening_Data.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Stop_Shunting_on_desk_opening_Data_UpperBitsNotSet(const Stop_Shunting_on_desk_opening_Data* p);

#endif // STOP_SHUNTING_ON_DESK_OPENING_DATA_UPPERBITSNOTSET_H_INCLUDED

