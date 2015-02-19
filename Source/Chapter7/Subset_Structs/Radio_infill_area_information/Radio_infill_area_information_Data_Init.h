
#ifndef RADIO_INFILL_AREA_INFORMATION_DATA_INIT_H_INCLUDED
#define RADIO_INFILL_AREA_INFORMATION_DATA_INIT_H_INCLUDED

#include "Radio_infill_area_information_Data.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void Radio_infill_area_information_Data_Init(Radio_infill_area_information_Data* p);


#endif // RADIO_INFILL_AREA_INFORMATION_DATA_INIT_H_INCLUDED

