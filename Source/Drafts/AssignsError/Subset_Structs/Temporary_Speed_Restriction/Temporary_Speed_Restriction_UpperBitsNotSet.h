
#ifndef TEMPORARY_SPEED_RESTRICTION_UPPERBITSNOTSET_H_INCLUDED
#define TEMPORARY_SPEED_RESTRICTION_UPPERBITSNOTSET_H_INCLUDED

#include "Temporary_Speed_Restriction.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Temporary_Speed_Restriction_UpperBitsNotSet(const Temporary_Speed_Restriction* p);

#endif // TEMPORARY_SPEED_RESTRICTION_UPPERBITSNOTSET_H_INCLUDED

