
#ifndef DATA_USED_BY_APPLICATIONS_OUTSIDE_THE_ERTMSETCS_SYSTEM_INIT_H_INCLUDED
#define DATA_USED_BY_APPLICATIONS_OUTSIDE_THE_ERTMSETCS_SYSTEM_INIT_H_INCLUDED

#include "Data_used_by_applications_outside_the_ERTMSETCS_system.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void Data_used_by_applications_outside_the_ERTMSETCS_system_Init(Data_used_by_applications_outside_the_ERTMSETCS_system* p);


#endif // DATA_USED_BY_APPLICATIONS_OUTSIDE_THE_ERTMSETCS_SYSTEM_INIT_H_INCLUDED

