
#ifndef ONBOARD_TELEPHONE_NUMBERS_INIT_H_INCLUDED
#define ONBOARD_TELEPHONE_NUMBERS_INIT_H_INCLUDED

#include "Onboard_telephone_numbers.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void Onboard_telephone_numbers_Init(Onboard_telephone_numbers* p);


#endif // ONBOARD_TELEPHONE_NUMBERS_INIT_H_INCLUDED

