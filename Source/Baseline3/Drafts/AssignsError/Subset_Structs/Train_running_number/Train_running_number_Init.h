
#ifndef TRAIN_RUNNING_NUMBER_INIT_H_INCLUDED
#define TRAIN_RUNNING_NUMBER_INIT_H_INCLUDED

#include "Train_running_number.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void Train_running_number_Init(Train_running_number* p);


#endif // TRAIN_RUNNING_NUMBER_INIT_H_INCLUDED

