
#ifndef NATIONAL_VALUES_INIT_H_INCLUDED
#define NATIONAL_VALUES_INIT_H_INCLUDED

#include "National_Values.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void National_Values_Init(National_Values* p);


#endif // NATIONAL_VALUES_INIT_H_INCLUDED

