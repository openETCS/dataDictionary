
#ifndef END_OF_INFORMATION_DATA_UPPERBITSNOTSET_H_INCLUDED
#define END_OF_INFORMATION_DATA_UPPERBITSNOTSET_H_INCLUDED

#include "End_of_Information_Data.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int End_of_Information_Data_UpperBitsNotSet(const End_of_Information_Data* p);

#endif // END_OF_INFORMATION_DATA_UPPERBITSNOTSET_H_INCLUDED

