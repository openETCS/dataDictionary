
#ifndef TRAIN_RUNNING_NUMBER_FROM_RBC_INIT_H_INCLUDED
#define TRAIN_RUNNING_NUMBER_FROM_RBC_INIT_H_INCLUDED

#include "Train_running_number_from_RBC.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void Train_running_number_from_RBC_Init(Train_running_number_from_RBC* p);


#endif // TRAIN_RUNNING_NUMBER_FROM_RBC_INIT_H_INCLUDED

