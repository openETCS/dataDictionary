
#ifndef SESSION_MANAGEMENT_UPPERBITSNOTSET_H_INCLUDED
#define SESSION_MANAGEMENT_UPPERBITSNOTSET_H_INCLUDED

#include "Session_Management_Core.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Session_Management_UpperBitsNotSet(const Session_Management_Core* p);

#endif // SESSION_MANAGEMENT_UPPERBITSNOTSET_H_INCLUDED

