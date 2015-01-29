
#ifndef BOTHWAYS_HEADER_UPPERBITSNOTSET_H_INCLUDED
#define BOTHWAYS_HEADER_UPPERBITSNOTSET_H_INCLUDED

#include "BothWays_Header.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int BothWays_Header_UpperBitsNotSet(const BothWays_Header* p);

#endif // BOTHWAYS_HEADER_UPPERBITSNOTSET_H_INCLUDED

