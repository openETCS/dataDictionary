
#ifndef EUROBALISE_HEADER_UPPERBITSNOTSET_H_INCLUDED
#define EUROBALISE_HEADER_UPPERBITSNOTSET_H_INCLUDED

#include "Eurobalise_Header.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Eurobalise_Header_UpperBitsNotSet(const Eurobalise_Header* p);

#endif // EUROBALISE_HEADER_UPPERBITSNOTSET_H_INCLUDED

