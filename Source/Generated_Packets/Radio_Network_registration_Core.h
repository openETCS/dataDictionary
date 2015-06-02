
#ifndef RADIO_NETWORK_REGISTRATION_CORE_H_INCLUDED
#define RADIO_NETWORK_REGISTRATION_CORE_H_INCLUDED

#include "Bitstream.h"

struct Radio_Network_registration_Core
{
    // TransmissionMedia=Balise, RBC, RIU
    // Packet to give the identity of the Radio Network to which
    // a registration shall be enforced.      
    // Packet Number = 45

    uint32_t  Q_DIR;            // # 2
    uint16_t  L_PACKET;         // # 13
    uint32_t  NID_MN;           // # 24
};

#ifdef __cplusplus

inline bool operator==(const Radio_Network_registration_Core& a, const Radio_Network_registration_Core& b)
{
    return
        (a.Q_DIR == b.Q_DIR) &&
        (a.L_PACKET == b.L_PACKET) &&
        (a.NID_MN == b.NID_MN);
}

inline bool operator!=(const Radio_Network_registration_Core& a, const Radio_Network_registration_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Radio_Network_registration_Core Radio_Network_registration_Core;

#define RADIO_NETWORK_REGISTRATION_CORE_BITSIZE 39

/*@
    logic integer BitSize{L}(Radio_Network_registration_Core* p) = RADIO_NETWORK_REGISTRATION_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Radio_Network_registration_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Radio_Network_registration_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Radio_Network_registration_Core* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->NID_MN);

    predicate ZeroInitialized(Radio_Network_registration_Core* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->NID_MN);

    predicate EqualBits(Bitstream* stream, integer pos, Radio_Network_registration_Core* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 39,  p->NID_MN);

    predicate UpperBitsNotSet(Radio_Network_registration_Core* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->NID_MN,           24);

*/

#endif // RADIO_NETWORK_REGISTRATION_CORE_H_INCLUDED

