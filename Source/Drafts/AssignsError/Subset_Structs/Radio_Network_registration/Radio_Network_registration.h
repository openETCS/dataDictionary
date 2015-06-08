
#ifndef RADIO_NETWORK_REGISTRATION_H_INCLUDED
#define RADIO_NETWORK_REGISTRATION_H_INCLUDED

#include "Bitstream.h"

struct Radio_Network_registration
{
    // TransmissionMedia=Balise, RBC, RIU
    // Packet to give the identity of the Radio Network to which
    // a registration shall be enforced.      
    // Packet Number = 45

    uint32_t  Q_DIR;            // # 2
    uint16_t  L_PACKET;         // # 13
    uint32_t  NID_MN;           // # 24
};

typedef struct Radio_Network_registration Radio_Network_registration;

#define RADIO_NETWORK_REGISTRATION_BITSIZE 39

/*@
    logic integer BitSize{L}(Radio_Network_registration* p) = RADIO_NETWORK_REGISTRATION_BITSIZE;

    logic integer MaxBitSize{L}(Radio_Network_registration* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Radio_Network_registration* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Radio_Network_registration* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->NID_MN);

    predicate ZeroInitialized(Radio_Network_registration* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->NID_MN);

    predicate EqualBits(Bitstream* stream, integer pos, Radio_Network_registration* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 39,  p->NID_MN);


    predicate UpperBitsNotSet(Radio_Network_registration* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->NID_MN,           24);

*/

#endif // RADIO_NETWORK_REGISTRATION_H_INCLUDED

