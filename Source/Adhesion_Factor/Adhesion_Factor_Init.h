
#ifndef ADHESION_FACTOR_INIT_H_INCLUDED
#define ADHESION_FACTOR_INIT_H_INCLUDED

#include "Adhesion_Factor.h"

/*@
    requires valid:           \valid(p);
    requires headerInvariant: Invariant(&p->header);
    requires headerZeroInit:  ZeroInitialized(&p->header);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void Adhesion_Factor_Init(Adhesion_Factor* p);


#endif // ADHESION_FACTOR_INIT_H_INCLUDED

