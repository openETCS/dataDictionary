
#ifndef VIRTUAL_BALISE_COVER_ORDER_INIT_H_INCLUDED
#define VIRTUAL_BALISE_COVER_ORDER_INIT_H_INCLUDED

#include "Virtual_Balise_Cover_order.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void Virtual_Balise_Cover_order_Init(Virtual_Balise_Cover_order* p);


#endif // VIRTUAL_BALISE_COVER_ORDER_INIT_H_INCLUDED

