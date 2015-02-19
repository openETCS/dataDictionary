
#ifndef VIRTUAL_BALISE_COVER_MARKER_DATA_UPPERBITSNOTSET_H_INCLUDED
#define VIRTUAL_BALISE_COVER_MARKER_DATA_UPPERBITSNOTSET_H_INCLUDED

#include "Virtual_Balise_Cover_marker_Data.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Virtual_Balise_Cover_marker_Data_UpperBitsNotSet(const Virtual_Balise_Cover_marker_Data* p);

#endif // VIRTUAL_BALISE_COVER_MARKER_DATA_UPPERBITSNOTSET_H_INCLUDED

