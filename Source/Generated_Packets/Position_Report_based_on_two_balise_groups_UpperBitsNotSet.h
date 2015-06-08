
#ifndef POSITION_REPORT_BASED_ON_TWO_BALISE_GROUPS_UPPERBITSNOTSET_H_INCLUDED
#define POSITION_REPORT_BASED_ON_TWO_BALISE_GROUPS_UPPERBITSNOTSET_H_INCLUDED

#include "Position_Report_based_on_two_balise_groups_Core.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Position_Report_based_on_two_balise_groups_UpperBitsNotSet(const Position_Report_based_on_two_balise_groups_Core* p);

#endif // POSITION_REPORT_BASED_ON_TWO_BALISE_GROUPS_UPPERBITSNOTSET_H_INCLUDED

