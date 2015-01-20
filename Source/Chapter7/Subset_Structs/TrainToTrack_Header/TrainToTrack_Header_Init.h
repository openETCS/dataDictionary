
#ifndef TRAINTOTRACK_HEADER_INIT_H_INCLUDED
#define TRAINTOTRACK_HEADER_INIT_H_INCLUDED

#include "TrainToTrack_Header.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;

    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void TrainToTrack_Header_Init(TrainToTrack_Header* p);


#endif // TRAINTOTRACK_HEADER_INIT_H_INCLUDED

