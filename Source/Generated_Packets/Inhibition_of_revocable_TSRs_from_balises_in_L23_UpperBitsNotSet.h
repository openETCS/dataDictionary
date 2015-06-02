
#ifndef INHIBITION_OF_REVOCABLE_TSRS_FROM_BALISES_IN_L23_UPPERBITSNOTSET_H_INCLUDED
#define INHIBITION_OF_REVOCABLE_TSRS_FROM_BALISES_IN_L23_UPPERBITSNOTSET_H_INCLUDED

#include "Inhibition_of_revocable_TSRs_from_balises_in_L23_Core.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Inhibition_of_revocable_TSRs_from_balises_in_L23_UpperBitsNotSet(const Inhibition_of_revocable_TSRs_from_balises_in_L23_Core* p);

#endif // INHIBITION_OF_REVOCABLE_TSRS_FROM_BALISES_IN_L23_UPPERBITSNOTSET_H_INCLUDED

