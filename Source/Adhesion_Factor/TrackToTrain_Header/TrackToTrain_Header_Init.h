
#ifndef TRACKTOTRAIN_HEADER_INIT_H_INCLUDED
#define TRACKTOTRAIN_HEADER_INIT_H_INCLUDED

#include "TrackToTrain_Header.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void TrackToTrain_Header_Init(TrackToTrain_Header* p);


#endif // TRACKTOTRAIN_HEADER_INIT_H_INCLUDED

