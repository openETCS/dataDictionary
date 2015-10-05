
#ifndef VIRTUAL_BALISE_COVER_MARKER_INIT_H_INCLUDED
#define VIRTUAL_BALISE_COVER_MARKER_INIT_H_INCLUDED

#include "Virtual_Balise_Cover_marker.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void Virtual_Balise_Cover_marker_Init(Virtual_Balise_Cover_marker* p);


#endif // VIRTUAL_BALISE_COVER_MARKER_INIT_H_INCLUDED

