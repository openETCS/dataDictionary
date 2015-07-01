
#ifndef LINKING_UPPERBITSNOTSET_H_INCLUDED
#define LINKING_UPPERBITSNOTSET_H_INCLUDED

#include "Linking_Core.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Linking_UpperBitsNotSet(const Linking_Core* p);

#endif // LINKING_UPPERBITSNOTSET_H_INCLUDED

