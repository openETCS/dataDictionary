
#ifndef TRAIN_RUNNING_NUMBER_UPPERBITSNOTSET_H_INCLUDED
#define TRAIN_RUNNING_NUMBER_UPPERBITSNOTSET_H_INCLUDED

#include "Adhesion_Factor.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Train_running_number_UpperBitsNotSet(const Train_running_number* p);

#endif // TRAIN_RUNNING_NUMBER_UPPERBITSNOTSET_H_INCLUDED

