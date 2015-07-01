
#ifndef MODE_PROFILE_UPPERBITSNOTSET_H_INCLUDED
#define MODE_PROFILE_UPPERBITSNOTSET_H_INCLUDED

#include "Mode_profile_Core.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Mode_profile_UpperBitsNotSet(const Mode_profile_Core* p);

#endif // MODE_PROFILE_UPPERBITSNOTSET_H_INCLUDED

