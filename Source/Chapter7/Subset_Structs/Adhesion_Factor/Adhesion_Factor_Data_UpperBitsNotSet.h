
#ifndef ADHESION_FACTOR_DATA_UPPERBITSNOTSET_H_INCLUDED
#define ADHESION_FACTOR_DATA_UPPERBITSNOTSET_H_INCLUDED

#include "Adhesion_Factor_Data.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Adhesion_Factor_Data_UpperBitsNotSet(const Adhesion_Factor_Data* p);

#endif // ADHESION_FACTOR_DATA_UPPERBITSNOTSET_H_INCLUDED

