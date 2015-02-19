
#ifndef RBC_TRANSITION_ORDER_DATA_INIT_H_INCLUDED
#define RBC_TRANSITION_ORDER_DATA_INIT_H_INCLUDED

#include "RBC_transition_order_Data.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void RBC_transition_order_Data_Init(RBC_transition_order_Data* p);


#endif // RBC_TRANSITION_ORDER_DATA_INIT_H_INCLUDED

