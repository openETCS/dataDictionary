
#ifndef TEMPORARY_SPEED_RESTRICTION_REVOCATION_UPPERBITSNOTSET_H_INCLUDED
#define TEMPORARY_SPEED_RESTRICTION_REVOCATION_UPPERBITSNOTSET_H_INCLUDED

#include "Adhesion_Factor.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Temporary_Speed_Restriction_Revocation_UpperBitsNotSet(const Temporary_Speed_Restriction_Revocation* p);

#endif // TEMPORARY_SPEED_RESTRICTION_REVOCATION_UPPERBITSNOTSET_H_INCLUDED

