
#ifndef ERROR_REPORTING_DATA_INIT_H_INCLUDED
#define ERROR_REPORTING_DATA_INIT_H_INCLUDED

#include "Error_Reporting_Data.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void Error_Reporting_Data_Init(Error_Reporting_Data* p);


#endif // ERROR_REPORTING_DATA_INIT_H_INCLUDED

