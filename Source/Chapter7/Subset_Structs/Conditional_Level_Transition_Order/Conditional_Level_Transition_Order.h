
#ifndef CONDITIONAL_LEVEL_TRANSITION_ORDER_H_INCLUDED
#define CONDITIONAL_LEVEL_TRANSITION_ORDER_H_INCLUDED

#include "Bitstream.h"

struct Conditional_Level_Transition_Order
{
    // TransmissionMedia=Balise
    // Packet for a conditional level transition. The successive M_LEVELTR go from the highest priority level to the lowest one.
    // Packet Number = 46

    uint64_t  NID_PACKET;       // # 8
    uint64_t  Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t  M_LEVELTR;        // # 3
    uint64_t  NID_NTC;          // # 8
    uint64_t  N_ITER;           // # 5// # 3// # 8
};

typedef struct Conditional_Level_Transition_Order Conditional_Level_Transition_Order;

#define CONDITIONAL_LEVEL_TRANSITION_ORDER_BITSIZE 50

/*@
    logic integer BitSize{L}(Conditional_Level_Transition_Order* p) = CONDITIONAL_LEVEL_TRANSITION_ORDER_BITSIZE;

    logic integer MaxBitSize{L}(Conditional_Level_Transition_Order* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Conditional_Level_Transition_Order* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Conditional_Level_Transition_Order* p) =
      Invariant(p->NID_PACKET)        &&
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->M_LEVELTR)         &&
      Invariant(p->NID_NTC)           &&
      Invariant(p->N_ITER)            &&
      Invariant(p->M_LEVELTR(k))      &&
      Invariant(p->NID_NTC(k));

    predicate ZeroInitialized(Conditional_Level_Transition_Order* p) =
      ZeroInitialized(p->NID_PACKET)        &&
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->M_LEVELTR)         &&
      ZeroInitialized(p->NID_NTC)           &&
      ZeroInitialized(p->N_ITER)            &&
      ZeroInitialized(p->M_LEVELTR(k))      &&
      ZeroInitialized(p->NID_NTC(k));

    predicate EqualBits(Bitstream* stream, integer pos, Conditional_Level_Transition_Order* p) =
      EqualBits(stream, pos,       pos + 8,   p->NID_PACKET)        &&
      EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR)             &&
      EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET)          &&
      EqualBits(stream, pos + 23,  pos + 26,  p->M_LEVELTR)         &&
      EqualBits(stream, pos + 26,  pos + 34,  p->NID_NTC)           &&
      EqualBits(stream, pos + 34,  pos + 39,  p->N_ITER)            &&
      EqualBits(stream, pos + 39,  pos + 42,  p->M_LEVELTR(k))      &&
      EqualBits(stream, pos + 42,  pos + 50,  p->NID_NTC(k));


    predicate UpperBitsNotSet(Conditional_Level_Transition_Order* p) =
      UpperBitsNotSet(p->NID_PACKET,       8)   &&
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->M_LEVELTR,        3)   &&
      UpperBitsNotSet(p->NID_NTC,          8)   &&
      UpperBitsNotSet(p->N_ITER,           5)   &&
      UpperBitsNotSet(p->M_LEVELTR(k),     3)   &&
      UpperBitsNotSet(p->NID_NTC(k),       8);

*/

#endif // CONDITIONAL_LEVEL_TRANSITION_ORDER_H_INCLUDED

