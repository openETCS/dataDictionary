
#ifndef TRACK_AHEAD_FREE_UP_TO_LEVEL_23_TRANSITION_LOCATION_INIT_H_INCLUDED
#define TRACK_AHEAD_FREE_UP_TO_LEVEL_23_TRANSITION_LOCATION_INIT_H_INCLUDED

#include "Track_Ahead_Free_up_to_level_23_transition_location.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void Track_Ahead_Free_up_to_level_23_transition_location_Init(Track_Ahead_Free_up_to_level_23_transition_location* p);


#endif // TRACK_AHEAD_FREE_UP_TO_LEVEL_23_TRANSITION_LOCATION_INIT_H_INCLUDED

