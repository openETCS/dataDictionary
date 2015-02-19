
#ifndef RADIO_INFILL_AREA_INFORMATION_DATA_UPPERBITSNOTSET_H_INCLUDED
#define RADIO_INFILL_AREA_INFORMATION_DATA_UPPERBITSNOTSET_H_INCLUDED

#include "Radio_infill_area_information_Data.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Radio_infill_area_information_Data_UpperBitsNotSet(const Radio_infill_area_information_Data* p);

#endif // RADIO_INFILL_AREA_INFORMATION_DATA_UPPERBITSNOTSET_H_INCLUDED

