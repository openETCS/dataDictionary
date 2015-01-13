
#ifndef VALIDATED_TRAIN_DATA_INIT_H_INCLUDED
#define VALIDATED_TRAIN_DATA_INIT_H_INCLUDED

#include "Validated_train_data.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void Validated_train_data_Init(Validated_train_data* p);


#endif // VALIDATED_TRAIN_DATA_INIT_H_INCLUDED

