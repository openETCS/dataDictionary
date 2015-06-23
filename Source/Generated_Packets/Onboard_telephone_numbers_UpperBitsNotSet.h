
#ifndef ONBOARD_TELEPHONE_NUMBERS_UPPERBITSNOTSET_H_INCLUDED
#define ONBOARD_TELEPHONE_NUMBERS_UPPERBITSNOTSET_H_INCLUDED

#include "Onboard_telephone_numbers_Core.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Onboard_telephone_numbers_UpperBitsNotSet(const Onboard_telephone_numbers_Core* p);

#endif // ONBOARD_TELEPHONE_NUMBERS_UPPERBITSNOTSET_H_INCLUDED

