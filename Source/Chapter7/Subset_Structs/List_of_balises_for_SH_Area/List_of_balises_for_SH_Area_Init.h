
#ifndef LIST_OF_BALISES_FOR_SH_AREA_INIT_H_INCLUDED
#define LIST_OF_BALISES_FOR_SH_AREA_INIT_H_INCLUDED

#include "List_of_balises_for_SH_Area.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void List_of_balises_for_SH_Area_Init(List_of_balises_for_SH_Area* p);


#endif // LIST_OF_BALISES_FOR_SH_AREA_INIT_H_INCLUDED

