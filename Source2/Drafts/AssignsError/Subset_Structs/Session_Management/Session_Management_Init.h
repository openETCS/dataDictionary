
#ifndef SESSION_MANAGEMENT_INIT_H_INCLUDED
#define SESSION_MANAGEMENT_INIT_H_INCLUDED

#include "Session_Management.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void Session_Management_Init(Session_Management* p);


#endif // SESSION_MANAGEMENT_INIT_H_INCLUDED

