
#ifndef DEFAULT_BALISE_OR_LOOP_OR_RIU_INFORMATION_DATA_UPPERBITSNOTSET_H_INCLUDED
#define DEFAULT_BALISE_OR_LOOP_OR_RIU_INFORMATION_DATA_UPPERBITSNOTSET_H_INCLUDED

#include "Default_balise_or_Loop_or_RIU_information_Data.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Default_balise_or_Loop_or_RIU_information_Data_UpperBitsNotSet(const Default_balise_or_Loop_or_RIU_information_Data* p);

#endif // DEFAULT_BALISE_OR_LOOP_OR_RIU_INFORMATION_DATA_UPPERBITSNOTSET_H_INCLUDED

