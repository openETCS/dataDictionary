
#ifndef GEOGRAPHICAL_POSITION_INFORMATION_INIT_H_INCLUDED
#define GEOGRAPHICAL_POSITION_INFORMATION_INIT_H_INCLUDED

#include "Geographical_Position_Information.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void Geographical_Position_Information_Init(Geographical_Position_Information* p);


#endif // GEOGRAPHICAL_POSITION_INFORMATION_INIT_H_INCLUDED

