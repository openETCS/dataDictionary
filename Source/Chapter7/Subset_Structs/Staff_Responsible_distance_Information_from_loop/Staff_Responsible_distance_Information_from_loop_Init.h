
#ifndef STAFF_RESPONSIBLE_DISTANCE_INFORMATION_FROM_LOOP_INIT_H_INCLUDED
#define STAFF_RESPONSIBLE_DISTANCE_INFORMATION_FROM_LOOP_INIT_H_INCLUDED

#include "Staff_Responsible_distance_Information_from_loop.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void Staff_Responsible_distance_Information_from_loop_Init(Staff_Responsible_distance_Information_from_loop* p);


#endif // STAFF_RESPONSIBLE_DISTANCE_INFORMATION_FROM_LOOP_INIT_H_INCLUDED

