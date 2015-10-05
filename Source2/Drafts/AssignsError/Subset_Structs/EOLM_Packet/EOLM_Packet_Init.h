
#ifndef EOLM_PACKET_INIT_H_INCLUDED
#define EOLM_PACKET_INIT_H_INCLUDED

#include "EOLM_Packet.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void EOLM_Packet_Init(EOLM_Packet* p);


#endif // EOLM_PACKET_INIT_H_INCLUDED

