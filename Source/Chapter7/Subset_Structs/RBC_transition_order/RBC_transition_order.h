
#ifndef RBC_TRANSITION_ORDER_H_INCLUDED
#define RBC_TRANSITION_ORDER_H_INCLUDED

#include "Bitstream.h"

struct RBC_transition_order
{
    // TransmissionMedia=Balise, RBC
    // Packet to order an RBC transition
    // Packet Number = 131

    uint64_t  NID_PACKET;       // # 8
    uint64_t  Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t  Q_SCALE;          // # 2
    uint64_t  D_RBCTR;          // # 15
    uint64_t  NID_C;            // # 10
    uint64_t  NID_RBC;          // # 14
    uint64_t  NID_RADIO;        // # 64
    uint64_t  Q_SLEEPSESSION;   // # 1
};

typedef struct RBC_transition_order RBC_transition_order;

#define RBC_TRANSITION_ORDER_BITSIZE 129

/*@
    logic integer BitSize{L}(RBC_transition_order* p) = RBC_TRANSITION_ORDER_BITSIZE;

    logic integer MaxBitSize{L}(RBC_transition_order* p) = BitSize(p);

    predicate Separated(Bitstream* stream, RBC_transition_order* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(RBC_transition_order* p) =
      Invariant(p->NID_PACKET)        &&
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->D_RBCTR)           &&
      Invariant(p->NID_C)             &&
      Invariant(p->NID_RBC)           &&
      Invariant(p->NID_RADIO)         &&
      Invariant(p->Q_SLEEPSESSION);

    predicate ZeroInitialized(RBC_transition_order* p) =
      ZeroInitialized(p->NID_PACKET)        &&
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->D_RBCTR)           &&
      ZeroInitialized(p->NID_C)             &&
      ZeroInitialized(p->NID_RBC)           &&
      ZeroInitialized(p->NID_RADIO)         &&
      ZeroInitialized(p->Q_SLEEPSESSION);

    predicate EqualBits(Bitstream* stream, integer pos, RBC_transition_order* p) =
      EqualBits(stream, pos,       pos + 8,   p->NID_PACKET)        &&
      EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR)             &&
      EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET)          &&
      EqualBits(stream, pos + 23,  pos + 25,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 25,  pos + 40,  p->D_RBCTR)           &&
      EqualBits(stream, pos + 40,  pos + 50,  p->NID_C)             &&
      EqualBits(stream, pos + 50,  pos + 64,  p->NID_RBC)           &&
      EqualBits(stream, pos + 64,  pos + 128, p->NID_RADIO)         &&
      EqualBits(stream, pos + 128, pos + 129, p->Q_SLEEPSESSION);


    predicate UpperBitsNotSet(RBC_transition_order* p) =
      UpperBitsNotSet(p->NID_PACKET,       8)   &&
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->D_RBCTR,          15)  &&
      UpperBitsNotSet(p->NID_C,            10)  &&
      UpperBitsNotSet(p->NID_RBC,          14)  &&
      UpperBitsNotSet(p->NID_RADIO,        64)  &&
      UpperBitsNotSet(p->Q_SLEEPSESSION,   1);

*/

#endif // RBC_TRANSITION_ORDER_H_INCLUDED

