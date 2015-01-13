
#ifndef GEOGRAPHICAL_POSITION_INFORMATION_UPPERBITSNOTSET_H_INCLUDED
#define GEOGRAPHICAL_POSITION_INFORMATION_UPPERBITSNOTSET_H_INCLUDED

#include "Adhesion_Factor.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Geographical_Position_Information_UpperBitsNotSet(const Geographical_Position_Information* p);

#endif // GEOGRAPHICAL_POSITION_INFORMATION_UPPERBITSNOTSET_H_INCLUDED

