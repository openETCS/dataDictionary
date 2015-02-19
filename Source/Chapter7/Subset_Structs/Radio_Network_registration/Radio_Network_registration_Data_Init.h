
#ifndef RADIO_NETWORK_REGISTRATION_DATA_INIT_H_INCLUDED
#define RADIO_NETWORK_REGISTRATION_DATA_INIT_H_INCLUDED

#include "Radio_Network_registration_Data.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void Radio_Network_registration_Data_Init(Radio_Network_registration_Data* p);


#endif // RADIO_NETWORK_REGISTRATION_DATA_INIT_H_INCLUDED

