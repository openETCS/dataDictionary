
#ifndef SYSTEM_VERSION_ORDER_UPPERBITSNOTSET_H_INCLUDED
#define SYSTEM_VERSION_ORDER_UPPERBITSNOTSET_H_INCLUDED

#include "System_Version_order_Core.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int System_Version_order_UpperBitsNotSet(const System_Version_order_Core* p);

#endif // SYSTEM_VERSION_ORDER_UPPERBITSNOTSET_H_INCLUDED

