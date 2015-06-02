
#ifndef EOLM_PACKET_UPPERBITSNOTSET_H_INCLUDED
#define EOLM_PACKET_UPPERBITSNOTSET_H_INCLUDED

#include "EOLM_Packet_Core.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int EOLM_Packet_UpperBitsNotSet(const EOLM_Packet_Core* p);

#endif // EOLM_PACKET_UPPERBITSNOTSET_H_INCLUDED

