
#ifndef EUROBALISE_HEADER_INIT_H_INCLUDED
#define EUROBALISE_HEADER_INIT_H_INCLUDED

#include "Eurobalise_Header.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void Eurobalise_Header_Init(Eurobalise_Header* p);


#endif // EUROBALISE_HEADER_INIT_H_INCLUDED

