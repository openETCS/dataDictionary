
#ifndef INHIBITION_OF_REVOCABLE_TSRS_FROM_BALISES_IN_L23_DATA_INIT_H_INCLUDED
#define INHIBITION_OF_REVOCABLE_TSRS_FROM_BALISES_IN_L23_DATA_INIT_H_INCLUDED

#include "Inhibition_of_revocable_TSRs_from_balises_in_L23_Data.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void Inhibition_of_revocable_TSRs_from_balises_in_L23_Data_Init(Inhibition_of_revocable_TSRs_from_balises_in_L23_Data* p);


#endif // INHIBITION_OF_REVOCABLE_TSRS_FROM_BALISES_IN_L23_DATA_INIT_H_INCLUDED

