
#ifndef REPOSITIONING_INFORMATION_INIT_H_INCLUDED
#define REPOSITIONING_INFORMATION_INIT_H_INCLUDED

#include "Repositioning_Information.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void Repositioning_Information_Init(Repositioning_Information* p);


#endif // REPOSITIONING_INFORMATION_INIT_H_INCLUDED

