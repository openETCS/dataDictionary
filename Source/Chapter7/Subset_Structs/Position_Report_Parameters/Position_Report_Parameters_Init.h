
#ifndef POSITION_REPORT_PARAMETERS_INIT_H_INCLUDED
#define POSITION_REPORT_PARAMETERS_INIT_H_INCLUDED

#include "Position_Report_Parameters.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void Position_Report_Parameters_Init(Position_Report_Parameters* p);


#endif // POSITION_REPORT_PARAMETERS_INIT_H_INCLUDED

