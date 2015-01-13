
#ifndef LIST_OF_BALISES_IN_SR_AUTHORITY_INIT_H_INCLUDED
#define LIST_OF_BALISES_IN_SR_AUTHORITY_INIT_H_INCLUDED

#include "List_of_Balises_in_SR_Authority.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void List_of_Balises_in_SR_Authority_Init(List_of_Balises_in_SR_Authority* p);


#endif // LIST_OF_BALISES_IN_SR_AUTHORITY_INIT_H_INCLUDED

