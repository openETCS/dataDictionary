
#ifndef HEADER_INIT_H_INCLUDED
#define HEADER_INIT_H_INCLUDED

#include "Header.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void Header_Init(Header* p);


#endif // HEADER_INIT_H_INCLUDED

