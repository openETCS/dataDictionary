
#ifndef NATIONAL_VALUES_UPPERBITSNOTSET_H_INCLUDED
#define NATIONAL_VALUES_UPPERBITSNOTSET_H_INCLUDED

#include "Adhesion_Factor.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int National_Values_UpperBitsNotSet(const National_Values* p);

#endif // NATIONAL_VALUES_UPPERBITSNOTSET_H_INCLUDED

