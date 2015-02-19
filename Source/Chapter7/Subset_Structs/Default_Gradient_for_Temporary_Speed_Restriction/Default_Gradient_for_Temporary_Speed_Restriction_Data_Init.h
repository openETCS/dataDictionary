
#ifndef DEFAULT_GRADIENT_FOR_TEMPORARY_SPEED_RESTRICTION_DATA_INIT_H_INCLUDED
#define DEFAULT_GRADIENT_FOR_TEMPORARY_SPEED_RESTRICTION_DATA_INIT_H_INCLUDED

#include "Default_Gradient_for_Temporary_Speed_Restriction_Data.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void Default_Gradient_for_Temporary_Speed_Restriction_Data_Init(Default_Gradient_for_Temporary_Speed_Restriction_Data* p);


#endif // DEFAULT_GRADIENT_FOR_TEMPORARY_SPEED_RESTRICTION_DATA_INIT_H_INCLUDED

