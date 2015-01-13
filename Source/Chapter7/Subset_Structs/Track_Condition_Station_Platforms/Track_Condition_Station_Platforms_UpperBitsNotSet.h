
#ifndef TRACK_CONDITION_STATION_PLATFORMS_UPPERBITSNOTSET_H_INCLUDED
#define TRACK_CONDITION_STATION_PLATFORMS_UPPERBITSNOTSET_H_INCLUDED

#include "Adhesion_Factor.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Track_Condition_Station_Platforms_UpperBitsNotSet(const Track_Condition_Station_Platforms* p);

#endif // TRACK_CONDITION_STATION_PLATFORMS_UPPERBITSNOTSET_H_INCLUDED

