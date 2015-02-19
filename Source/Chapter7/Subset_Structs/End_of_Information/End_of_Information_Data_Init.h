
#ifndef END_OF_INFORMATION_DATA_INIT_H_INCLUDED
#define END_OF_INFORMATION_DATA_INIT_H_INCLUDED

#include "End_of_Information_Data.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void End_of_Information_Data_Init(End_of_Information_Data* p);


#endif // END_OF_INFORMATION_DATA_INIT_H_INCLUDED

