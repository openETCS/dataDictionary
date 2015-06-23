
#ifndef VALIDATED_TRAIN_DATA_CORE_2_UPPERBITSNOTSET_H_INCLUDED
#define VALIDATED_TRAIN_DATA_CORE_2_UPPERBITSNOTSET_H_INCLUDED

#include "Validated_train_data_Core_2.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Validated_train_data_Core_2_UpperBitsNotSet(const Validated_train_data_Core_2* p);

#endif // VALIDATED_TRAIN_DATA_CORE_2_UPPERBITSNOTSET_H_INCLUDED

