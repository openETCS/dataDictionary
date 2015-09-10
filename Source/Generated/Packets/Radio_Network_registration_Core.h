
#ifndef RADIO_NETWORK_REGISTRATION_CORE_H_INCLUDED
#define RADIO_NETWORK_REGISTRATION_CORE_H_INCLUDED

#include "Bitstream.h"

struct Radio_Network_registration_Core
{
    // TransmissionMedia=Balise, RBC, RIU
    // Packet to give the identity of the Radio Network to which
    // a registration shall be enforced.
    // Packet Number = 45

    uint64_t   Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t  NID_MN;           // # 24
};

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

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Radio_Network_registration_UpperBitsNotSet(const Radio_Network_registration_Core* p);

/*@
    requires valid_stream:      Writeable(stream);
    requires stream_invariant:  Invariant(stream, MaxBitSize(p));
    requires valid_package:     \valid_read(p);
    requires invariant:         Invariant(p);
    requires separation:        Separated(stream, p);

    assigns stream->bitpos;
    assigns stream->addr[0..(stream->size-1)];

    behavior normal_case:
      assumes Normal{Pre}(stream, MaxBitSize(p)) && UpperBitsNotSet{Pre}(p);

      assigns stream->bitpos;
      assigns stream->addr[0..(stream->size-1)];

      ensures result:     \result == 1;
      ensures increment:  stream->bitpos == \old(stream->bitpos) + BitSize(p);
      ensures left:       Unchanged{Here,Old}(stream, 0, \old(stream->bitpos));
      ensures middle:     EqualBits(stream, \old(stream->bitpos), p);
      ensures right:      Unchanged{Here,Old}(stream, stream->bitpos, 8 * stream->size);

    behavior values_too_big:
      assumes Normal{Pre}(stream, MaxBitSize(p)) && !UpperBitsNotSet{Pre}(p);

      assigns \nothing;

      ensures result:        \result == -2;

    behavior invalid_bit_sequence:
      assumes !Normal{Pre}(stream, MaxBitSize(p));

      assigns \nothing;

      ensures result:       \result == -1;

    complete behaviors;
    disjoint behaviors;
*/
int Radio_Network_registration_Encoder(Bitstream* stream, const Radio_Network_registration_Core* p);

/*@
    requires valid_stream:      Readable(stream);
    requires stream_invariant:  Invariant(stream, MaxBitSize(p));
    requires valid_package:     \valid(p);
    requires separation:        Separated(stream, p);

    assigns stream->bitpos;
    assigns *p;

    ensures unchanged:          Unchanged{Here,Old}(stream, 0, 8*stream->size);

    behavior normal_case:
      assumes Normal{Pre}(stream, MaxBitSize(p));

      assigns stream->bitpos;
      assigns *p;

      ensures invariant:  Invariant(p);
      ensures result:     \result == 1;
      ensures increment:  stream->bitpos == \old(stream->bitpos) + BitSize(p);
      ensures equal:      EqualBits(stream, \old(stream->bitpos), p);
      ensures upper:      UpperBitsNotSet(p);

    behavior error_case:
      assumes !Normal{Pre}(stream, MaxBitSize(p));

      assigns \nothing;

      ensures result: \result == 0;

    complete behaviors;
    disjoint behaviors;
*/
int Radio_Network_registration_Decoder(Bitstream* stream, Radio_Network_registration_Core* p);

#ifdef __cplusplus

#include <iostream>

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

inline int encode(Bitstream& stream, const Radio_Network_registration_Core& p)
{
    return Radio_Network_registration_Encoder(&stream, &p);
}

inline int decode(Bitstream& stream, Radio_Network_registration_Core& p)
{
    return Radio_Network_registration_Decoder(&stream, &p);
}

#endif // __cplusplus

#endif // RADIO_NETWORK_REGISTRATION_CORE_H_INCLUDED

