
#ifndef LEVEL_1_MOVEMENT_AUTHORITY_UPPERBITSNOTSET_H_INCLUDED
#define LEVEL_1_MOVEMENT_AUTHORITY_UPPERBITSNOTSET_H_INCLUDED

#include "Adhesion_Factor.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Level_1_Movement_Authority_UpperBitsNotSet(const Level_1_Movement_Authority* p);

#endif // LEVEL_1_MOVEMENT_AUTHORITY_UPPERBITSNOTSET_H_INCLUDED

