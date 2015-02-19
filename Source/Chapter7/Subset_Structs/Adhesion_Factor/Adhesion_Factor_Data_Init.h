
#ifndef ADHESION_FACTOR_DATA_INIT_H_INCLUDED
#define ADHESION_FACTOR_DATA_INIT_H_INCLUDED

#include "Adhesion_Factor_Data.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void Adhesion_Factor_Data_Init(Adhesion_Factor_Data* p);


#endif // ADHESION_FACTOR_DATA_INIT_H_INCLUDED

