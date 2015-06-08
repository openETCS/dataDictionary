
#ifndef INFILL_LOCATION_REFERENCE_INIT_H_INCLUDED
#define INFILL_LOCATION_REFERENCE_INIT_H_INCLUDED

#include "Infill_location_reference.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void Infill_location_reference_Init(Infill_location_reference* p);


#endif // INFILL_LOCATION_REFERENCE_INIT_H_INCLUDED

