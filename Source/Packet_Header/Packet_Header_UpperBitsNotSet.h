
#ifndef PACKET_HEADER_UPPERBITSNOTSET_H_INCLUDED
#define PACKET_HEADER_UPPERBITSNOTSET_H_INCLUDED

#include "Packet_Header.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Packet_Header_UpperBitsNotSet(const Packet_Header* p);

#endif // PACKET_HEADER_UPPERBITSNOTSET_H_INCLUDED

