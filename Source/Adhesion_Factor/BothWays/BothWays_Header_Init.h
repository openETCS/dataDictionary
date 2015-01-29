
#ifndef BOTHWAYS_HEADER_INIT_H_INCLUDED
#define BOTHWAYS_HEADER_INIT_H_INCLUDED

#include "BothWays_Header.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void BothWays_Header_Init(BothWays_Header* p);


#endif // BOTHWAYS_HEADER_INIT_H_INCLUDED

