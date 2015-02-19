
#ifndef DANGER_FOR_SHUNTING_INFORMATION_DATA_UPPERBITSNOTSET_H_INCLUDED
#define DANGER_FOR_SHUNTING_INFORMATION_DATA_UPPERBITSNOTSET_H_INCLUDED

#include "Danger_for_Shunting_information_Data.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Danger_for_Shunting_information_Data_UpperBitsNotSet(const Danger_for_Shunting_information_Data* p);

#endif // DANGER_FOR_SHUNTING_INFORMATION_DATA_UPPERBITSNOTSET_H_INCLUDED

