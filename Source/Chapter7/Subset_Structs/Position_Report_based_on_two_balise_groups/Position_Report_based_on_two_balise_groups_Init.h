
#ifndef POSITION_REPORT_BASED_ON_TWO_BALISE_GROUPS_INIT_H_INCLUDED
#define POSITION_REPORT_BASED_ON_TWO_BALISE_GROUPS_INIT_H_INCLUDED

#include "Position_Report_based_on_two_balise_groups.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void Position_Report_based_on_two_balise_groups_Init(Position_Report_based_on_two_balise_groups* p);


#endif // POSITION_REPORT_BASED_ON_TWO_BALISE_GROUPS_INIT_H_INCLUDED

