
#ifndef NATIONAL_VALUES_UPPERBITSNOTSET_H_INCLUDED
#define NATIONAL_VALUES_UPPERBITSNOTSET_H_INCLUDED

#include "National_Values_Core.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int National_Values_UpperBitsNotSet(const National_Values_Core* p);

#endif // NATIONAL_VALUES_UPPERBITSNOTSET_H_INCLUDED

