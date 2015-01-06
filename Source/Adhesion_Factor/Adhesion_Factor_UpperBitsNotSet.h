
#ifndef ADHESION_FACTOR_UPPERBITSNOTSET_H_INCLUDED
#define ADHESION_FACTOR_UPPERBITSNOTSET_H_INCLUDED

#include "Adhesion_Factor.h"

/*@
    requires valid:  \valid_read(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Adhesion_Factor_UpperBitsNotSet(const Adhesion_Factor* p);

#endif // ADHESION_FACTOR_UPPERBITSNOTSET_H_INCLUDED

