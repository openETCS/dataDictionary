
#ifndef REPOSITIONING_INFORMATION_DATA_UPPERBITSNOTSET_H_INCLUDED
#define REPOSITIONING_INFORMATION_DATA_UPPERBITSNOTSET_H_INCLUDED

#include "Repositioning_Information_Data.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Repositioning_Information_Data_UpperBitsNotSet(const Repositioning_Information_Data* p);

#endif // REPOSITIONING_INFORMATION_DATA_UPPERBITSNOTSET_H_INCLUDED

