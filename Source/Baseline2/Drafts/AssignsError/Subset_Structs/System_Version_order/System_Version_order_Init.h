
#ifndef SYSTEM_VERSION_ORDER_INIT_H_INCLUDED
#define SYSTEM_VERSION_ORDER_INIT_H_INCLUDED

#include "System_Version_order.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void System_Version_order_Init(System_Version_order* p);


#endif // SYSTEM_VERSION_ORDER_INIT_H_INCLUDED

