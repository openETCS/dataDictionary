
#ifndef SESSION_MANAGEMENT_DATA_INIT_H_INCLUDED
#define SESSION_MANAGEMENT_DATA_INIT_H_INCLUDED

#include "Session_Management_Data.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void Session_Management_Data_Init(Session_Management_Data* p);


#endif // SESSION_MANAGEMENT_DATA_INIT_H_INCLUDED

