
#ifndef POSITION_REPORT_INIT_H_INCLUDED
#define POSITION_REPORT_INIT_H_INCLUDED

#include "Position_Report.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void Position_Report_Init(Position_Report* p);


#endif // POSITION_REPORT_INIT_H_INCLUDED

