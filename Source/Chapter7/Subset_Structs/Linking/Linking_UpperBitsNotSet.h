
#ifndef LINKING_UPPERBITSNOTSET_H_INCLUDED
#define LINKING_UPPERBITSNOTSET_H_INCLUDED

#include "Adhesion_Factor.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Linking_UpperBitsNotSet(const Linking* p);

#endif // LINKING_UPPERBITSNOTSET_H_INCLUDED

