
#ifndef RBC_TRANSITION_ORDER_DATA_H_INCLUDED
#define RBC_TRANSITION_ORDER_DATA_H_INCLUDED

#include "Bitstream.h"

struct RBC_transition_order_Data
{
    // TransmissionMedia=Balise, RBC
    // Packet to order an RBC transition
    // Packet Number = 131

    uint32_t  Q_DIR;            // # 2
    uint32_t  Q_SCALE;          // # 2
    uint16_t  D_RBCTR;          // # 15
    uint16_t  NID_C;            // # 10
    uint16_t  NID_RBC;          // # 14
    uint64_t  NID_RADIO;        // # 64
    uint32_t  Q_SLEEPSESSION;   // # 1
};

typedef struct RBC_transition_order_Data RBC_transition_order_Data;

#define RBC_TRANSITION_ORDER_DATA_BITSIZE 121

/*@
    logic integer BitSize{L}(RBC_transition_order_Data* p) = RBC_TRANSITION_ORDER_DATA_BITSIZE;

    logic integer MaxBitSize{L}(RBC_transition_order_Data* p) = BitSize(p);

    predicate Separated(Bitstream* stream, RBC_transition_order_Data* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(RBC_transition_order_Data* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->D_RBCTR)           &&
      Invariant(p->NID_C)             &&
      Invariant(p->NID_RBC)           &&
      Invariant(p->NID_RADIO)         &&
      Invariant(p->Q_SLEEPSESSION);

    predicate ZeroInitialized(RBC_transition_order_Data* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->D_RBCTR)           &&
      ZeroInitialized(p->NID_C)             &&
      ZeroInitialized(p->NID_RBC)           &&
      ZeroInitialized(p->NID_RADIO)         &&
      ZeroInitialized(p->Q_SLEEPSESSION);

    predicate EqualBits(Bitstream* stream, integer pos, RBC_transition_order_Data* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 17,  pos + 32,  p->D_RBCTR)           &&
      EqualBits(stream, pos + 32,  pos + 42,  p->NID_C)             &&
      EqualBits(stream, pos + 42,  pos + 56,  p->NID_RBC)           &&
      EqualBits(stream, pos + 56,  pos + 120, p->NID_RADIO)         &&
      EqualBits(stream, pos + 120, pos + 121, p->Q_SLEEPSESSION);


    predicate UpperBitsNotSet(RBC_transition_order_Data* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->D_RBCTR,          15)  &&
      UpperBitsNotSet(p->NID_C,            10)  &&
      UpperBitsNotSet(p->NID_RBC,          14)  &&
      UpperBitsNotSet(p->NID_RADIO,        64)  &&
      UpperBitsNotSet(p->Q_SLEEPSESSION,   1);

*/

#endif // RBC_TRANSITION_ORDER_DATA_H_INCLUDED

