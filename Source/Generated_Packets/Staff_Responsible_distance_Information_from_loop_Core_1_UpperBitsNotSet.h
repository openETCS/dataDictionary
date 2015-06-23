
#ifndef STAFF_RESPONSIBLE_DISTANCE_INFORMATION_FROM_LOOP_CORE_1_UPPERBITSNOTSET_H_INCLUDED
#define STAFF_RESPONSIBLE_DISTANCE_INFORMATION_FROM_LOOP_CORE_1_UPPERBITSNOTSET_H_INCLUDED

#include "Staff_Responsible_distance_Information_from_loop_Core_1.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Staff_Responsible_distance_Information_from_loop_Core_1_UpperBitsNotSet(const Staff_Responsible_distance_Information_from_loop_Core_1* p);

#endif // STAFF_RESPONSIBLE_DISTANCE_INFORMATION_FROM_LOOP_CORE_1_UPPERBITSNOTSET_H_INCLUDED

