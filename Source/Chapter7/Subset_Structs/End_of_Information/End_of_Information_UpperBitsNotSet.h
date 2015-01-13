
#ifndef END_OF_INFORMATION_UPPERBITSNOTSET_H_INCLUDED
#define END_OF_INFORMATION_UPPERBITSNOTSET_H_INCLUDED

#include "Adhesion_Factor.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int End_of_Information_UpperBitsNotSet(const End_of_Information* p);

#endif // END_OF_INFORMATION_UPPERBITSNOTSET_H_INCLUDED

