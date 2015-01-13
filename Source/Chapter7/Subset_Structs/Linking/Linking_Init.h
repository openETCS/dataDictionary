
#ifndef LINKING_INIT_H_INCLUDED
#define LINKING_INIT_H_INCLUDED

#include "Linking.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void Linking_Init(Linking* p);


#endif // LINKING_INIT_H_INCLUDED

