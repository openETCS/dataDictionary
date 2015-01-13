
#ifndef DATA_USED_BY_APPLICATIONS_OUTSIDE_THE_ERTMS_OR_ETCS_SYSTEM_UPPERBITSNOTSET_H_INCLUDED
#define DATA_USED_BY_APPLICATIONS_OUTSIDE_THE_ERTMS_OR_ETCS_SYSTEM_UPPERBITSNOTSET_H_INCLUDED

#include "Data_used_by_applications_outside_the_ERTMS_or_ETCS_system.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Data_used_by_applications_outside_the_ERTMS_or_ETCS_system_UpperBitsNotSet(const Data_used_by_applications_outside_the_ERTMS_or_ETCS_system* p);

#endif // DATA_USED_BY_APPLICATIONS_OUTSIDE_THE_ERTMS_OR_ETCS_SYSTEM_UPPERBITSNOTSET_H_INCLUDED

