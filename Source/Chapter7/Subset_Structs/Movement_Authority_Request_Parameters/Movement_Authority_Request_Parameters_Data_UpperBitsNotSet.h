
#ifndef MOVEMENT_AUTHORITY_REQUEST_PARAMETERS_DATA_UPPERBITSNOTSET_H_INCLUDED
#define MOVEMENT_AUTHORITY_REQUEST_PARAMETERS_DATA_UPPERBITSNOTSET_H_INCLUDED

#include "Movement_Authority_Request_Parameters_Data.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Movement_Authority_Request_Parameters_Data_UpperBitsNotSet(const Movement_Authority_Request_Parameters_Data* p);

#endif // MOVEMENT_AUTHORITY_REQUEST_PARAMETERS_DATA_UPPERBITSNOTSET_H_INCLUDED

