
#ifndef PACKET_FOR_SENDING_PLAIN_TEXT_MESSAGES_INIT_H_INCLUDED
#define PACKET_FOR_SENDING_PLAIN_TEXT_MESSAGES_INIT_H_INCLUDED

#include "Packet_for_sending_plain_text_messages.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void Packet_for_sending_plain_text_messages_Init(Packet_for_sending_plain_text_messages* p);


#endif // PACKET_FOR_SENDING_PLAIN_TEXT_MESSAGES_INIT_H_INCLUDED

