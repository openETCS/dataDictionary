
#ifndef POSITION_REPORT_UPPERBITSNOTSET_H_INCLUDED
#define POSITION_REPORT_UPPERBITSNOTSET_H_INCLUDED

#include "Position_Report_Core.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Position_Report_UpperBitsNotSet(const Position_Report_Core* p);

#endif // POSITION_REPORT_UPPERBITSNOTSET_H_INCLUDED

