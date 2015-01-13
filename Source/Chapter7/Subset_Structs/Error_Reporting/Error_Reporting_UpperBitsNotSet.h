
#ifndef ERROR_REPORTING_UPPERBITSNOTSET_H_INCLUDED
#define ERROR_REPORTING_UPPERBITSNOTSET_H_INCLUDED

#include "Adhesion_Factor.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Error_Reporting_UpperBitsNotSet(const Error_Reporting* p);

#endif // ERROR_REPORTING_UPPERBITSNOTSET_H_INCLUDED

