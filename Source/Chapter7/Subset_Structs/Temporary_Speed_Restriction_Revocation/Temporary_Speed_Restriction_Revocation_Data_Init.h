
#ifndef TEMPORARY_SPEED_RESTRICTION_REVOCATION_DATA_INIT_H_INCLUDED
#define TEMPORARY_SPEED_RESTRICTION_REVOCATION_DATA_INIT_H_INCLUDED

#include "Temporary_Speed_Restriction_Revocation_Data.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void Temporary_Speed_Restriction_Revocation_Data_Init(Temporary_Speed_Restriction_Revocation_Data* p);


#endif // TEMPORARY_SPEED_RESTRICTION_REVOCATION_DATA_INIT_H_INCLUDED

