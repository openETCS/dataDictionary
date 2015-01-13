
#ifndef MODE_PROFILE_UPPERBITSNOTSET_H_INCLUDED
#define MODE_PROFILE_UPPERBITSNOTSET_H_INCLUDED

#include "Adhesion_Factor.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Mode_profile_UpperBitsNotSet(const Mode_profile* p);

#endif // MODE_PROFILE_UPPERBITSNOTSET_H_INCLUDED

