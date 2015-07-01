
#ifndef ROUTE_SUITABILITY_DATA_CORE_1_UPPERBITSNOTSET_H_INCLUDED
#define ROUTE_SUITABILITY_DATA_CORE_1_UPPERBITSNOTSET_H_INCLUDED

#include "Route_Suitability_Data_Core_1.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Route_Suitability_Data_Core_1_UpperBitsNotSet(const Route_Suitability_Data_Core_1* p);

#endif // ROUTE_SUITABILITY_DATA_CORE_1_UPPERBITSNOTSET_H_INCLUDED

