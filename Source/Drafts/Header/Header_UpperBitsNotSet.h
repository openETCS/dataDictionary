
#ifndef HEADER_UPPERBITSNOTSET_H_INCLUDED
#define HEADER_UPPERBITSNOTSET_H_INCLUDED

#include "Header.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Header_UpperBitsNotSet(const Header* p);

#endif // HEADER_UPPERBITSNOTSET_H_INCLUDED

