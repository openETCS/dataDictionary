
#ifndef POSITION_REPORT_PARAMETERS_CORE_1_UPPERBITSNOTSET_H_INCLUDED
#define POSITION_REPORT_PARAMETERS_CORE_1_UPPERBITSNOTSET_H_INCLUDED

#include "Position_Report_Parameters_Core_1.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Position_Report_Parameters_Core_1_UpperBitsNotSet(const Position_Report_Parameters_Core_1* p);

#endif // POSITION_REPORT_PARAMETERS_CORE_1_UPPERBITSNOTSET_H_INCLUDED

