
#ifndef DATA_USED_BY_APPLICATIONS_OUTSIDE_THE_ERTMSETCS_SYSTEM_UPPERBITSNOTSET_H_INCLUDED
#define DATA_USED_BY_APPLICATIONS_OUTSIDE_THE_ERTMSETCS_SYSTEM_UPPERBITSNOTSET_H_INCLUDED

#include "Data_used_by_applications_outside_the_ERTMSETCS_system_Core.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Data_used_by_applications_outside_the_ERTMSETCS_system_UpperBitsNotSet(const Data_used_by_applications_outside_the_ERTMSETCS_system_Core* p);

#endif // DATA_USED_BY_APPLICATIONS_OUTSIDE_THE_ERTMSETCS_SYSTEM_UPPERBITSNOTSET_H_INCLUDED

