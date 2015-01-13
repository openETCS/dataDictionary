
#ifndef INFILL_LOCATION_REFERENCE_UPPERBITSNOTSET_H_INCLUDED
#define INFILL_LOCATION_REFERENCE_UPPERBITSNOTSET_H_INCLUDED

#include "Adhesion_Factor.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Infill_location_reference_UpperBitsNotSet(const Infill_location_reference* p);

#endif // INFILL_LOCATION_REFERENCE_UPPERBITSNOTSET_H_INCLUDED

