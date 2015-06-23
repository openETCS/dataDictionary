
#ifndef ROUTE_SUITABILITY_DATA_UPPERBITSNOTSET_H_INCLUDED
#define ROUTE_SUITABILITY_DATA_UPPERBITSNOTSET_H_INCLUDED

#include "Route_Suitability_Data_Core.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Route_Suitability_Data_UpperBitsNotSet(const Route_Suitability_Data_Core* p);

#endif // ROUTE_SUITABILITY_DATA_UPPERBITSNOTSET_H_INCLUDED

