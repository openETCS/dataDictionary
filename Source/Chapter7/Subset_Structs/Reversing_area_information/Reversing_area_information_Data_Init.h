
#ifndef REVERSING_AREA_INFORMATION_DATA_INIT_H_INCLUDED
#define REVERSING_AREA_INFORMATION_DATA_INIT_H_INCLUDED

#include "Reversing_area_information_Data.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void Reversing_area_information_Data_Init(Reversing_area_information_Data* p);


#endif // REVERSING_AREA_INFORMATION_DATA_INIT_H_INCLUDED

