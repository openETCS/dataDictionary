
#ifndef REVERSING_AREA_INFORMATION_DATA_UPPERBITSNOTSET_H_INCLUDED
#define REVERSING_AREA_INFORMATION_DATA_UPPERBITSNOTSET_H_INCLUDED

#include "Reversing_area_information_Data.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Reversing_area_information_Data_UpperBitsNotSet(const Reversing_area_information_Data* p);

#endif // REVERSING_AREA_INFORMATION_DATA_UPPERBITSNOTSET_H_INCLUDED

