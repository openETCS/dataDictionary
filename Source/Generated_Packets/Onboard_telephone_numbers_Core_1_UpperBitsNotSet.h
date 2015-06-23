
#ifndef ONBOARD_TELEPHONE_NUMBERS_CORE_1_UPPERBITSNOTSET_H_INCLUDED
#define ONBOARD_TELEPHONE_NUMBERS_CORE_1_UPPERBITSNOTSET_H_INCLUDED

#include "Onboard_telephone_numbers_Core_1.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Onboard_telephone_numbers_Core_1_UpperBitsNotSet(const Onboard_telephone_numbers_Core_1* p);

#endif // ONBOARD_TELEPHONE_NUMBERS_CORE_1_UPPERBITSNOTSET_H_INCLUDED

