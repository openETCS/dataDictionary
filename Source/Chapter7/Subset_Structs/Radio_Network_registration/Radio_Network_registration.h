
#ifndef RADIO_NETWORK_REGISTRATION_H_INCLUDED
#define RADIO_NETWORK_REGISTRATION_H_INCLUDED

#include "Bitstream.h"

struct Radio_Network_registration
{
    // TransmissionMedia=Balise, RBC, RIU
    // Packet to give the identity of the Radio Network to which a registration shall be enforced.
    // Packet Number = 45

    uint64_t  NID_PACKET;       // # 8
    uint64_t  Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t  NID_MN;           // # 24
};

typedef struct Radio_Network_registration Radio_Network_registration;

#define RADIO_NETWORK_REGISTRATION_BITSIZE 47

/*@
    logic integer BitSize{L}(Radio_Network_registration* p) = RADIO_NETWORK_REGISTRATION_BITSIZE;

    logic integer MaxBitSize{L}(Radio_Network_registration* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Radio_Network_registration* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Radio_Network_registration* p) =
      Invariant(p->NID_PACKET)        &&
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->NID_MN);

    predicate ZeroInitialized(Radio_Network_registration* p) =
      ZeroInitialized(p->NID_PACKET)        &&
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->NID_MN);

    predicate EqualBits(Bitstream* stream, integer pos, Radio_Network_registration* p) =
      EqualBits(stream, pos,       pos + 8,   p->NID_PACKET)        &&
      EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR)             &&
      EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET)          &&
      EqualBits(stream, pos + 23,  pos + 47,  p->NID_MN);


    predicate UpperBitsNotSet(Radio_Network_registration* p) =
      UpperBitsNotSet(p->NID_PACKET,       8)   &&
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->NID_MN,           24);

*/

#endif // RADIO_NETWORK_REGISTRATION_H_INCLUDED

