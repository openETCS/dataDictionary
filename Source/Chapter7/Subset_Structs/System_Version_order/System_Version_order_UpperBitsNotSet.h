
#ifndef SYSTEM_VERSION_ORDER_UPPERBITSNOTSET_H_INCLUDED
#define SYSTEM_VERSION_ORDER_UPPERBITSNOTSET_H_INCLUDED

#include "Adhesion_Factor.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int System_Version_order_UpperBitsNotSet(const System_Version_order* p);

#endif // SYSTEM_VERSION_ORDER_UPPERBITSNOTSET_H_INCLUDED

