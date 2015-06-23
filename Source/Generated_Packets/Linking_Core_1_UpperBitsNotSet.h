
#ifndef LINKING_CORE_1_UPPERBITSNOTSET_H_INCLUDED
#define LINKING_CORE_1_UPPERBITSNOTSET_H_INCLUDED

#include "Linking_Core_1.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Linking_Core_1_UpperBitsNotSet(const Linking_Core_1* p);

#endif // LINKING_CORE_1_UPPERBITSNOTSET_H_INCLUDED

