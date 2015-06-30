
#ifndef RADIO_NETWORK_REGISTRATION_CORE_H_INCLUDED
#define RADIO_NETWORK_REGISTRATION_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

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

inline std::ostream& operator<<(std::ostream& stream, const Radio_Network_registration_Core& p)
{
    stream 
       << +p.Q_DIR << ','
       << +p.L_PACKET << ','
       << +p.NID_MN;

    return stream;
}

inline bool operator==(const Radio_Network_registration_Core& a, const Radio_Network_registration_Core& b)
{
    bool status = true;
    
    status = status && (a.Q_DIR == b.Q_DIR);
    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.NID_MN == b.NID_MN);

    return status;
}

inline bool operator!=(const Radio_Network_registration_Core& a, const Radio_Network_registration_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Radio_Network_registration_Core Radio_Network_registration_Core;

#define RADIO_NETWORK_REGISTRATION_CORE_BITSIZE 1694

/*@
    logic integer BitSize{L}(Radio_Network_registration_Core* p) = RADIO_NETWORK_REGISTRATION_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Radio_Network_registration_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Radio_Network_registration_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Radio_Network_registration_Core* p) = \true;

    predicate ZeroInitialized(Radio_Network_registration_Core* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Radio_Network_registration_Core* p) = \true;

    predicate UpperBitsNotSet(Radio_Network_registration_Core* p) = \true;

*/

#endif // RADIO_NETWORK_REGISTRATION_CORE_H_INCLUDED

