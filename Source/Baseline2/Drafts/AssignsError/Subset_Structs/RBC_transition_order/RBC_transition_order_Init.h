
#ifndef RBC_TRANSITION_ORDER_INIT_H_INCLUDED
#define RBC_TRANSITION_ORDER_INIT_H_INCLUDED

#include "RBC_transition_order.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void RBC_transition_order_Init(RBC_transition_order* p);


#endif // RBC_TRANSITION_ORDER_INIT_H_INCLUDED

