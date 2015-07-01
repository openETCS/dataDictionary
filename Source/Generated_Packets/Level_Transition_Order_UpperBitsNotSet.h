
#ifndef LEVEL_TRANSITION_ORDER_UPPERBITSNOTSET_H_INCLUDED
#define LEVEL_TRANSITION_ORDER_UPPERBITSNOTSET_H_INCLUDED

#include "Level_Transition_Order_Core.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Level_Transition_Order_UpperBitsNotSet(const Level_Transition_Order_Core* p);

#endif // LEVEL_TRANSITION_ORDER_UPPERBITSNOTSET_H_INCLUDED

