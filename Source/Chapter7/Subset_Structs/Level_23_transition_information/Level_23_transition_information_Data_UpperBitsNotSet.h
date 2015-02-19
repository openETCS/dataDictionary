
#ifndef LEVEL_23_TRANSITION_INFORMATION_DATA_UPPERBITSNOTSET_H_INCLUDED
#define LEVEL_23_TRANSITION_INFORMATION_DATA_UPPERBITSNOTSET_H_INCLUDED

#include "Level_23_transition_information_Data.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Level_23_transition_information_Data_UpperBitsNotSet(const Level_23_transition_information_Data* p);

#endif // LEVEL_23_TRANSITION_INFORMATION_DATA_UPPERBITSNOTSET_H_INCLUDED

