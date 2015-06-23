
#ifndef LEVEL_1_MOVEMENT_AUTHORITY_CORE_1_UPPERBITSNOTSET_H_INCLUDED
#define LEVEL_1_MOVEMENT_AUTHORITY_CORE_1_UPPERBITSNOTSET_H_INCLUDED

#include "Level_1_Movement_Authority_Core_1.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Level_1_Movement_Authority_Core_1_UpperBitsNotSet(const Level_1_Movement_Authority_Core_1* p);

#endif // LEVEL_1_MOVEMENT_AUTHORITY_CORE_1_UPPERBITSNOTSET_H_INCLUDED

