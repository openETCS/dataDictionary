
#ifndef DEFAULT_BALISE_OR_LOOP_OR_RIU_INFORMATION_DATA_INIT_H_INCLUDED
#define DEFAULT_BALISE_OR_LOOP_OR_RIU_INFORMATION_DATA_INIT_H_INCLUDED

#include "Default_balise_or_Loop_or_RIU_information_Data.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void Default_balise_or_Loop_or_RIU_information_Data_Init(Default_balise_or_Loop_or_RIU_information_Data* p);


#endif // DEFAULT_BALISE_OR_LOOP_OR_RIU_INFORMATION_DATA_INIT_H_INCLUDED

