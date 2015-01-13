
#ifndef LEVEL_TRANSITION_ORDER_INIT_H_INCLUDED
#define LEVEL_TRANSITION_ORDER_INIT_H_INCLUDED

#include "Level_Transition_Order.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void Level_Transition_Order_Init(Level_Transition_Order* p);


#endif // LEVEL_TRANSITION_ORDER_INIT_H_INCLUDED

