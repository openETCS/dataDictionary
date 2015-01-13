
#ifndef VIRTUAL_BALISE_COVER_MARKER_UPPERBITSNOTSET_H_INCLUDED
#define VIRTUAL_BALISE_COVER_MARKER_UPPERBITSNOTSET_H_INCLUDED

#include "Adhesion_Factor.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Virtual_Balise_Cover_marker_UpperBitsNotSet(const Virtual_Balise_Cover_marker* p);

#endif // VIRTUAL_BALISE_COVER_MARKER_UPPERBITSNOTSET_H_INCLUDED

