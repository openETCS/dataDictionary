
#ifndef TRACKTOTRAIN_HEADER_UPPERBITSNOTSET_H_INCLUDED
#define TRACKTOTRAIN_HEADER_UPPERBITSNOTSET_H_INCLUDED

#include "TrackToTrain_Header.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int TrackToTrain_Header_UpperBitsNotSet(const TrackToTrain_Header* p);

#endif // TRACKTOTRAIN_HEADER_UPPERBITSNOTSET_H_INCLUDED

