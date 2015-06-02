
#ifndef SESSION_MANAGEMENT_WITH_NEIGHBOURING_RADIO_INFILL_UNIT_UPPERBITSNOTSET_H_INCLUDED
#define SESSION_MANAGEMENT_WITH_NEIGHBOURING_RADIO_INFILL_UNIT_UPPERBITSNOTSET_H_INCLUDED

#include "Session_Management_with_neighbouring_Radio_Infill_Unit_Core.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Session_Management_with_neighbouring_Radio_Infill_Unit_UpperBitsNotSet(const Session_Management_with_neighbouring_Radio_Infill_Unit_Core* p);

#endif // SESSION_MANAGEMENT_WITH_NEIGHBOURING_RADIO_INFILL_UNIT_UPPERBITSNOTSET_H_INCLUDED

