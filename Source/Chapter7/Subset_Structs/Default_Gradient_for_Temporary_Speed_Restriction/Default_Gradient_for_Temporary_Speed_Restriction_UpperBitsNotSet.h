
#ifndef DEFAULT_GRADIENT_FOR_TEMPORARY_SPEED_RESTRICTION_UPPERBITSNOTSET_H_INCLUDED
#define DEFAULT_GRADIENT_FOR_TEMPORARY_SPEED_RESTRICTION_UPPERBITSNOTSET_H_INCLUDED

#include "Adhesion_Factor.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Default_Gradient_for_Temporary_Speed_Restriction_UpperBitsNotSet(const Default_Gradient_for_Temporary_Speed_Restriction* p);

#endif // DEFAULT_GRADIENT_FOR_TEMPORARY_SPEED_RESTRICTION_UPPERBITSNOTSET_H_INCLUDED

