
#ifndef LIST_OF_BALISES_FOR_SH_AREA_CORE_1_UPPERBITSNOTSET_H_INCLUDED
#define LIST_OF_BALISES_FOR_SH_AREA_CORE_1_UPPERBITSNOTSET_H_INCLUDED

#include "List_of_balises_for_SH_Area_Core_1.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int List_of_balises_for_SH_Area_Core_1_UpperBitsNotSet(const List_of_balises_for_SH_Area_Core_1* p);

#endif // LIST_OF_BALISES_FOR_SH_AREA_CORE_1_UPPERBITSNOTSET_H_INCLUDED

