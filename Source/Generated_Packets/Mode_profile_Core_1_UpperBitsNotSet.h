
#ifndef MODE_PROFILE_CORE_1_UPPERBITSNOTSET_H_INCLUDED
#define MODE_PROFILE_CORE_1_UPPERBITSNOTSET_H_INCLUDED

#include "Mode_profile_Core_1.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Mode_profile_Core_1_UpperBitsNotSet(const Mode_profile_Core_1* p);

#endif // MODE_PROFILE_CORE_1_UPPERBITSNOTSET_H_INCLUDED

