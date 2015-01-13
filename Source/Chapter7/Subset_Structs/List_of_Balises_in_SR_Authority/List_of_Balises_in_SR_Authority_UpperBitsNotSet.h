
#ifndef LIST_OF_BALISES_IN_SR_AUTHORITY_UPPERBITSNOTSET_H_INCLUDED
#define LIST_OF_BALISES_IN_SR_AUTHORITY_UPPERBITSNOTSET_H_INCLUDED

#include "Adhesion_Factor.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int List_of_Balises_in_SR_Authority_UpperBitsNotSet(const List_of_Balises_in_SR_Authority* p);

#endif // LIST_OF_BALISES_IN_SR_AUTHORITY_UPPERBITSNOTSET_H_INCLUDED

