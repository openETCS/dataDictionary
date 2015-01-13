
#ifndef CONDITIONAL_LEVEL_TRANSITION_ORDER_INIT_H_INCLUDED
#define CONDITIONAL_LEVEL_TRANSITION_ORDER_INIT_H_INCLUDED

#include "Conditional_Level_Transition_Order.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void Conditional_Level_Transition_Order_Init(Conditional_Level_Transition_Order* p);


#endif // CONDITIONAL_LEVEL_TRANSITION_ORDER_INIT_H_INCLUDED

