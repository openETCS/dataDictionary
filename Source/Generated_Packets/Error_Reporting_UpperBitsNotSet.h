
#ifndef ERROR_REPORTING_UPPERBITSNOTSET_H_INCLUDED
#define ERROR_REPORTING_UPPERBITSNOTSET_H_INCLUDED

#include "Error_Reporting_Core.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Error_Reporting_UpperBitsNotSet(const Error_Reporting_Core* p);

#endif // ERROR_REPORTING_UPPERBITSNOTSET_H_INCLUDED

