
#ifndef RADIO_NETWORK_REGISTRATION_UPPERBITSNOTSET_H_INCLUDED
#define RADIO_NETWORK_REGISTRATION_UPPERBITSNOTSET_H_INCLUDED

#include "Radio_Network_registration_Core.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Radio_Network_registration_UpperBitsNotSet(const Radio_Network_registration_Core* p);

#endif // RADIO_NETWORK_REGISTRATION_UPPERBITSNOTSET_H_INCLUDED

