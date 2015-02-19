
#ifndef ERROR_REPORTING_DATA_UPPERBITSNOTSET_H_INCLUDED
#define ERROR_REPORTING_DATA_UPPERBITSNOTSET_H_INCLUDED

#include "Error_Reporting_Data.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Error_Reporting_Data_UpperBitsNotSet(const Error_Reporting_Data* p);

#endif // ERROR_REPORTING_DATA_UPPERBITSNOTSET_H_INCLUDED

