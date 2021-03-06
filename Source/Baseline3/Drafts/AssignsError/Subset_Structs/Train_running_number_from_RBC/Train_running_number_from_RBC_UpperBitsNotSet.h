
#ifndef TRAIN_RUNNING_NUMBER_FROM_RBC_UPPERBITSNOTSET_H_INCLUDED
#define TRAIN_RUNNING_NUMBER_FROM_RBC_UPPERBITSNOTSET_H_INCLUDED

#include "Train_running_number_from_RBC.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Train_running_number_from_RBC_UpperBitsNotSet(const Train_running_number_from_RBC* p);

#endif // TRAIN_RUNNING_NUMBER_FROM_RBC_UPPERBITSNOTSET_H_INCLUDED

