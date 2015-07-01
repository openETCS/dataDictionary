
#ifndef LIST_OF_BALISES_FOR_SH_AREA_UPPERBITSNOTSET_H_INCLUDED
#define LIST_OF_BALISES_FOR_SH_AREA_UPPERBITSNOTSET_H_INCLUDED

#include "List_of_balises_for_SH_Area_Core.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int List_of_balises_for_SH_Area_UpperBitsNotSet(const List_of_balises_for_SH_Area_Core* p);

#endif // LIST_OF_BALISES_FOR_SH_AREA_UPPERBITSNOTSET_H_INCLUDED

