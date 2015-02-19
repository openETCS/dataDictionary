
#ifndef EOLM_PACKET_DATA_INIT_H_INCLUDED
#define EOLM_PACKET_DATA_INIT_H_INCLUDED

#include "EOLM_Packet_Data.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void EOLM_Packet_Data_Init(EOLM_Packet_Data* p);


#endif // EOLM_PACKET_DATA_INIT_H_INCLUDED

