
#ifndef STOP_IF_IN_STAFF_RESPONSIBLE_INIT_H_INCLUDED
#define STOP_IF_IN_STAFF_RESPONSIBLE_INIT_H_INCLUDED

#include "Stop_if_in_Staff_Responsible.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void Stop_if_in_Staff_Responsible_Init(Stop_if_in_Staff_Responsible* p);


#endif // STOP_IF_IN_STAFF_RESPONSIBLE_INIT_H_INCLUDED

