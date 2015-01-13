
#ifndef POSITION_REPORT_PARAMETERS_UPPERBITSNOTSET_H_INCLUDED
#define POSITION_REPORT_PARAMETERS_UPPERBITSNOTSET_H_INCLUDED

#include "Adhesion_Factor.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Position_Report_Parameters_UpperBitsNotSet(const Position_Report_Parameters* p);

#endif // POSITION_REPORT_PARAMETERS_UPPERBITSNOTSET_H_INCLUDED

