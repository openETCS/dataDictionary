
#ifndef CONDITIONAL_LEVEL_TRANSITION_ORDER_UPPERBITSNOTSET_H_INCLUDED
#define CONDITIONAL_LEVEL_TRANSITION_ORDER_UPPERBITSNOTSET_H_INCLUDED

#include "Adhesion_Factor.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Conditional_Level_Transition_Order_UpperBitsNotSet(const Conditional_Level_Transition_Order* p);

#endif // CONDITIONAL_LEVEL_TRANSITION_ORDER_UPPERBITSNOTSET_H_INCLUDED

