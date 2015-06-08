
#ifndef INFILL_LOCATION_REFERENCE_UPPERBITSNOTSET_H_INCLUDED
#define INFILL_LOCATION_REFERENCE_UPPERBITSNOTSET_H_INCLUDED

#include "Infill_location_reference_Core.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Infill_location_reference_UpperBitsNotSet(const Infill_location_reference_Core* p);

#endif // INFILL_LOCATION_REFERENCE_UPPERBITSNOTSET_H_INCLUDED

