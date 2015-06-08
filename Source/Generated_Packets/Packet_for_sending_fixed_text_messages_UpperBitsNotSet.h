
#ifndef PACKET_FOR_SENDING_FIXED_TEXT_MESSAGES_UPPERBITSNOTSET_H_INCLUDED
#define PACKET_FOR_SENDING_FIXED_TEXT_MESSAGES_UPPERBITSNOTSET_H_INCLUDED

#include "Packet_for_sending_fixed_text_messages_Core.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Packet_for_sending_fixed_text_messages_UpperBitsNotSet(const Packet_for_sending_fixed_text_messages_Core* p);

#endif // PACKET_FOR_SENDING_FIXED_TEXT_MESSAGES_UPPERBITSNOTSET_H_INCLUDED

