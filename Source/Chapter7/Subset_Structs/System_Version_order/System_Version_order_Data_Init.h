
#ifndef SYSTEM_VERSION_ORDER_DATA_INIT_H_INCLUDED
#define SYSTEM_VERSION_ORDER_DATA_INIT_H_INCLUDED

#include "System_Version_order_Data.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void System_Version_order_Data_Init(System_Version_order_Data* p);


#endif // SYSTEM_VERSION_ORDER_DATA_INIT_H_INCLUDED

