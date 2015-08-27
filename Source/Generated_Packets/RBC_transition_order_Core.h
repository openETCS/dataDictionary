
#ifndef RBC_TRANSITION_ORDER_CORE_H_INCLUDED
#define RBC_TRANSITION_ORDER_CORE_H_INCLUDED

#include "Bitstream.h"

struct RBC_transition_order_Core
{
    // TransmissionMedia=Balise, RBC
    // Packet to order an RBC transition     
    // Packet Number = 131

    uint64_t  Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t  Q_SCALE;          // # 2
    uint64_t  D_RBCTR;          // # 15
    uint64_t  NID_C;            // # 10
    uint64_t  NID_RBC;          // # 14
    uint64_t  NID_RADIO;        // # 64
    uint64_t  Q_SLEEPSESSION;   // # 1
};

#ifdef __cplusplus

#include <iostream>

inline std::ostream& operator<<(std::ostream& stream, const RBC_transition_order_Core& p)
{
    stream 
       << +p.Q_DIR << ','
       << +p.L_PACKET << ','
       << +p.Q_SCALE << ','
       << +p.D_RBCTR << ','
       << +p.NID_C << ','
       << +p.NID_RBC << ','
       << +p.NID_RADIO << ','
       << +p.Q_SLEEPSESSION;

    return stream;
}

inline bool operator==(const RBC_transition_order_Core& a, const RBC_transition_order_Core& b)
{
    bool status = true;
    
    status = status && (a.Q_DIR == b.Q_DIR);
    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.Q_SCALE == b.Q_SCALE);
    status = status && (a.D_RBCTR == b.D_RBCTR);
    status = status && (a.NID_C == b.NID_C);
    status = status && (a.NID_RBC == b.NID_RBC);
    status = status && (a.NID_RADIO == b.NID_RADIO);
    status = status && (a.Q_SLEEPSESSION == b.Q_SLEEPSESSION);

    return status;
}

inline bool operator!=(const RBC_transition_order_Core& a, const RBC_transition_order_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct RBC_transition_order_Core RBC_transition_order_Core;

#define RBC_TRANSITION_ORDER_CORE_BITSIZE 121

/*@
    logic integer BitSize{L}(RBC_transition_order_Core* p) = RBC_TRANSITION_ORDER_CORE_BITSIZE;

    logic integer MaxBitSize{L}(RBC_transition_order_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, RBC_transition_order_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(RBC_transition_order_Core* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->D_RBCTR)           &&
      Invariant(p->NID_C)             &&
      Invariant(p->NID_RBC)           &&
      Invariant(p->NID_RADIO)         &&
      Invariant(p->Q_SLEEPSESSION);

    predicate ZeroInitialized(RBC_transition_order_Core* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->D_RBCTR)           &&
      ZeroInitialized(p->NID_C)             &&
      ZeroInitialized(p->NID_RBC)           &&
      ZeroInitialized(p->NID_RADIO)         &&
      ZeroInitialized(p->Q_SLEEPSESSION);

    predicate EqualBits(Bitstream* stream, integer pos, RBC_transition_order_Core* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 17,  pos + 32,  p->D_RBCTR)           &&
      EqualBits(stream, pos + 32,  pos + 42,  p->NID_C)             &&
      EqualBits(stream, pos + 42,  pos + 56,  p->NID_RBC)           &&
      EqualBits(stream, pos + 56,  pos + 120, p->NID_RADIO)         &&
      EqualBits(stream, pos + 120, pos + 121, p->Q_SLEEPSESSION);

    predicate UpperBitsNotSet(RBC_transition_order_Core* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->D_RBCTR,          15)  &&
      UpperBitsNotSet(p->NID_C,            10)  &&
      UpperBitsNotSet(p->NID_RBC,          14)  &&
      UpperBitsNotSet(p->NID_RADIO,        64)  &&
      UpperBitsNotSet(p->Q_SLEEPSESSION,   1);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int RBC_transition_order_UpperBitsNotSet(const RBC_transition_order_Core* p);

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
int RBC_transition_order_Encoder(Bitstream* stream, const RBC_transition_order_Core* p);

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
int RBC_transition_order_Decoder(Bitstream* stream, RBC_transition_order_Core* p);

#endif // RBC_TRANSITION_ORDER_CORE_H_INCLUDED

