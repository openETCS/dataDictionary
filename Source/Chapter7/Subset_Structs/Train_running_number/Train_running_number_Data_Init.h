
#ifndef TRAIN_RUNNING_NUMBER_DATA_INIT_H_INCLUDED
#define TRAIN_RUNNING_NUMBER_DATA_INIT_H_INCLUDED

#include "Train_running_number_Data.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void Train_running_number_Data_Init(Train_running_number_Data* p);


#endif // TRAIN_RUNNING_NUMBER_DATA_INIT_H_INCLUDED

