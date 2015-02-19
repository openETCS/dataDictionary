
#ifndef REVERSING_SUPERVISION_INFORMATION_DATA_INIT_H_INCLUDED
#define REVERSING_SUPERVISION_INFORMATION_DATA_INIT_H_INCLUDED

#include "Reversing_supervision_information_Data.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void Reversing_supervision_information_Data_Init(Reversing_supervision_information_Data* p);


#endif // REVERSING_SUPERVISION_INFORMATION_DATA_INIT_H_INCLUDED

