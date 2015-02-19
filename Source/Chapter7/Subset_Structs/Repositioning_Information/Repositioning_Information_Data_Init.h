
#ifndef REPOSITIONING_INFORMATION_DATA_INIT_H_INCLUDED
#define REPOSITIONING_INFORMATION_DATA_INIT_H_INCLUDED

#include "Repositioning_Information_Data.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void Repositioning_Information_Data_Init(Repositioning_Information_Data* p);


#endif // REPOSITIONING_INFORMATION_DATA_INIT_H_INCLUDED

