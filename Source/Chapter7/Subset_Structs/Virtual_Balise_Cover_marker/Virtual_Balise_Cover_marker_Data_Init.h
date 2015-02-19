
#ifndef VIRTUAL_BALISE_COVER_MARKER_DATA_INIT_H_INCLUDED
#define VIRTUAL_BALISE_COVER_MARKER_DATA_INIT_H_INCLUDED

#include "Virtual_Balise_Cover_marker_Data.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void Virtual_Balise_Cover_marker_Data_Init(Virtual_Balise_Cover_marker_Data* p);


#endif // VIRTUAL_BALISE_COVER_MARKER_DATA_INIT_H_INCLUDED

