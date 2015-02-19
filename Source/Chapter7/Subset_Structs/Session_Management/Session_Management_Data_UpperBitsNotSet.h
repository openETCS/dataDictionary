
#ifndef SESSION_MANAGEMENT_DATA_UPPERBITSNOTSET_H_INCLUDED
#define SESSION_MANAGEMENT_DATA_UPPERBITSNOTSET_H_INCLUDED

#include "Session_Management_Data.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Session_Management_Data_UpperBitsNotSet(const Session_Management_Data* p);

#endif // SESSION_MANAGEMENT_DATA_UPPERBITSNOTSET_H_INCLUDED

