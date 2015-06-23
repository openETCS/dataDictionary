
#ifndef NATIONAL_VALUES_CORE_1_UPPERBITSNOTSET_H_INCLUDED
#define NATIONAL_VALUES_CORE_1_UPPERBITSNOTSET_H_INCLUDED

#include "National_Values_Core_1.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int National_Values_Core_1_UpperBitsNotSet(const National_Values_Core_1* p);

#endif // NATIONAL_VALUES_CORE_1_UPPERBITSNOTSET_H_INCLUDED

