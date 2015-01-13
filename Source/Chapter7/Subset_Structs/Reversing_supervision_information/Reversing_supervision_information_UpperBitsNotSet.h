
#ifndef REVERSING_SUPERVISION_INFORMATION_UPPERBITSNOTSET_H_INCLUDED
#define REVERSING_SUPERVISION_INFORMATION_UPPERBITSNOTSET_H_INCLUDED

#include "Adhesion_Factor.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Reversing_supervision_information_UpperBitsNotSet(const Reversing_supervision_information* p);

#endif // REVERSING_SUPERVISION_INFORMATION_UPPERBITSNOTSET_H_INCLUDED

