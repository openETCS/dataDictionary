
#ifndef REPOSITIONING_INFORMATION_UPPERBITSNOTSET_H_INCLUDED
#define REPOSITIONING_INFORMATION_UPPERBITSNOTSET_H_INCLUDED

#include "Adhesion_Factor.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Repositioning_Information_UpperBitsNotSet(const Repositioning_Information* p);

#endif // REPOSITIONING_INFORMATION_UPPERBITSNOTSET_H_INCLUDED

