
#ifndef SYSTEM_VERSION_ORDER_DATA_UPPERBITSNOTSET_H_INCLUDED
#define SYSTEM_VERSION_ORDER_DATA_UPPERBITSNOTSET_H_INCLUDED

#include "System_Version_order_Data.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int System_Version_order_Data_UpperBitsNotSet(const System_Version_order_Data* p);

#endif // SYSTEM_VERSION_ORDER_DATA_UPPERBITSNOTSET_H_INCLUDED

