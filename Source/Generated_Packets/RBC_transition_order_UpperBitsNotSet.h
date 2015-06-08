
#ifndef RBC_TRANSITION_ORDER_UPPERBITSNOTSET_H_INCLUDED
#define RBC_TRANSITION_ORDER_UPPERBITSNOTSET_H_INCLUDED

#include "RBC_transition_order_Core.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int RBC_transition_order_UpperBitsNotSet(const RBC_transition_order_Core* p);

#endif // RBC_TRANSITION_ORDER_UPPERBITSNOTSET_H_INCLUDED

