
#ifndef UPPERBITSNOTSET_H_INCLUDED
#define UPPERBITSNOTSET_H_INCLUDED

#include "FramaCBits.h"

// not an inline function because it cannot verified automatically right now

/*@
    requires pre: length <= 64;

    assigns \nothing;

    ensures  not_set: \result <==> UpperBitsNotSet(value, length);
*/
int UpperBitsNotSet64(uint64_t value, uint32_t length);


#endif  // UPPERBITSNOTSET_H_INCLUDED

