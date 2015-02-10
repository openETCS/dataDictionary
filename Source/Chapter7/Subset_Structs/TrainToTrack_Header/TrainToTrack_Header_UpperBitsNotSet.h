
#ifndef TRAINTOTRACK_HEADER_UPPERBITSNOTSET_H_INCLUDED
#define TRAINTOTRACK_HEADER_UPPERBITSNOTSET_H_INCLUDED

#include "TrainToTrack_Header.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int TrainToTrack_Header_UpperBitsNotSet(const TrainToTrack_Header* p);

#endif // TRAINTOTRACK_HEADER_UPPERBITSNOTSET_H_INCLUDED

