
#ifndef ERROR_REPORTING_INIT_H_INCLUDED
#define ERROR_REPORTING_INIT_H_INCLUDED

#include "Error_Reporting.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void Error_Reporting_Init(Error_Reporting* p);


#endif // ERROR_REPORTING_INIT_H_INCLUDED

