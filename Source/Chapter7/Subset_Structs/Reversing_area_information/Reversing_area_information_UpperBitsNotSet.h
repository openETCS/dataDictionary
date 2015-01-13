
#ifndef REVERSING_AREA_INFORMATION_UPPERBITSNOTSET_H_INCLUDED
#define REVERSING_AREA_INFORMATION_UPPERBITSNOTSET_H_INCLUDED

#include "Reversing_area_information.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Reversing_area_information_UpperBitsNotSet(const Reversing_area_information* p);

#endif // REVERSING_AREA_INFORMATION_UPPERBITSNOTSET_H_INCLUDED

