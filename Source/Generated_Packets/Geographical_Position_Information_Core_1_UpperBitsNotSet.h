
#ifndef GEOGRAPHICAL_POSITION_INFORMATION_CORE_1_UPPERBITSNOTSET_H_INCLUDED
#define GEOGRAPHICAL_POSITION_INFORMATION_CORE_1_UPPERBITSNOTSET_H_INCLUDED

#include "Geographical_Position_Information_Core_1.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Geographical_Position_Information_Core_1_UpperBitsNotSet(const Geographical_Position_Information_Core_1* p);

#endif // GEOGRAPHICAL_POSITION_INFORMATION_CORE_1_UPPERBITSNOTSET_H_INCLUDED

