
#ifndef TRAIN_RUNNING_NUMBER_DATA_UPPERBITSNOTSET_H_INCLUDED
#define TRAIN_RUNNING_NUMBER_DATA_UPPERBITSNOTSET_H_INCLUDED

#include "Train_running_number_Data.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Train_running_number_Data_UpperBitsNotSet(const Train_running_number_Data* p);

#endif // TRAIN_RUNNING_NUMBER_DATA_UPPERBITSNOTSET_H_INCLUDED

