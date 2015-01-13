
#ifndef TRACK_CONDITION_STATION_PLATFORMS_INIT_H_INCLUDED
#define TRACK_CONDITION_STATION_PLATFORMS_INIT_H_INCLUDED

#include "Track_Condition_Station_Platforms.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void Track_Condition_Station_Platforms_Init(Track_Condition_Station_Platforms* p);


#endif // TRACK_CONDITION_STATION_PLATFORMS_INIT_H_INCLUDED

