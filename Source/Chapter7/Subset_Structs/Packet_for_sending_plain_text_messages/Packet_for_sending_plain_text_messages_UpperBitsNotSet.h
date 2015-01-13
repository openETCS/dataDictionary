
#ifndef PACKET_FOR_SENDING_PLAIN_TEXT_MESSAGES_UPPERBITSNOTSET_H_INCLUDED
#define PACKET_FOR_SENDING_PLAIN_TEXT_MESSAGES_UPPERBITSNOTSET_H_INCLUDED

#include "Adhesion_Factor.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Packet_for_sending_plain_text_messages_UpperBitsNotSet(const Packet_for_sending_plain_text_messages* p);

#endif // PACKET_FOR_SENDING_PLAIN_TEXT_MESSAGES_UPPERBITSNOTSET_H_INCLUDED

