
#ifndef LEVEL_TRANSITION_ORDER_H_INCLUDED
#define LEVEL_TRANSITION_ORDER_H_INCLUDED

#include "Bitstream.h"

struct Level_Transition_Order
{
    // TransmissionMedia=Any
    // Packet to identify where a level transition shall take place. In case of mixed levels, the successive M_LEVELTR go from the highest priority level to the lowest one.
    // Packet Number = 41

    uint64_t  NID_PACKET;       // # 8
    uint64_t  Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t  Q_SCALE;          // # 2
    uint64_t  D_LEVELTR;        // # 15
    uint64_t  M_LEVELTR;        // # 3
    uint64_t  NID_NTC;          // # 8
    uint64_t  L_ACKLEVELTR;     // # 15
    uint64_t  N_ITER;           // # 5// # 3// # 8// # 15
};

typedef struct Level_Transition_Order Level_Transition_Order;

#define LEVEL_TRANSITION_ORDER_BITSIZE 97

/*@
    logic integer BitSize{L}(Level_Transition_Order* p) = LEVEL_TRANSITION_ORDER_BITSIZE;

    logic integer MaxBitSize{L}(Level_Transition_Order* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Level_Transition_Order* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Level_Transition_Order* p) =
      Invariant(p->NID_PACKET)        &&
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->D_LEVELTR)         &&
      Invariant(p->M_LEVELTR)         &&
      Invariant(p->NID_NTC)           &&
      Invariant(p->L_ACKLEVELTR)      &&
      Invariant(p->N_ITER)            &&
      Invariant(p->M_LEVELTR(k))      &&
      Invariant(p->NID_NTC(k))        &&
      Invariant(p->L_ACKLEVELTR(k));

    predicate ZeroInitialized(Level_Transition_Order* p) =
      ZeroInitialized(p->NID_PACKET)        &&
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->D_LEVELTR)         &&
      ZeroInitialized(p->M_LEVELTR)         &&
      ZeroInitialized(p->NID_NTC)           &&
      ZeroInitialized(p->L_ACKLEVELTR)      &&
      ZeroInitialized(p->N_ITER)            &&
      ZeroInitialized(p->M_LEVELTR(k))      &&
      ZeroInitialized(p->NID_NTC(k))        &&
      ZeroInitialized(p->L_ACKLEVELTR(k));

    predicate EqualBits(Bitstream* stream, integer pos, Level_Transition_Order* p) =
      EqualBits(stream, pos,       pos + 8,   p->NID_PACKET)        &&
      EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR)             &&
      EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET)          &&
      EqualBits(stream, pos + 23,  pos + 25,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 25,  pos + 40,  p->D_LEVELTR)         &&
      EqualBits(stream, pos + 40,  pos + 43,  p->M_LEVELTR)         &&
      EqualBits(stream, pos + 43,  pos + 51,  p->NID_NTC)           &&
      EqualBits(stream, pos + 51,  pos + 66,  p->L_ACKLEVELTR)      &&
      EqualBits(stream, pos + 66,  pos + 71,  p->N_ITER)            &&
      EqualBits(stream, pos + 71,  pos + 74,  p->M_LEVELTR(k))      &&
      EqualBits(stream, pos + 74,  pos + 82,  p->NID_NTC(k))        &&
      EqualBits(stream, pos + 82,  pos + 97,  p->L_ACKLEVELTR(k));


    predicate UpperBitsNotSet(Level_Transition_Order* p) =
      UpperBitsNotSet(p->NID_PACKET,       8)   &&
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->D_LEVELTR,        15)  &&
      UpperBitsNotSet(p->M_LEVELTR,        3)   &&
      UpperBitsNotSet(p->NID_NTC,          8)   &&
      UpperBitsNotSet(p->L_ACKLEVELTR,     15)  &&
      UpperBitsNotSet(p->N_ITER,           5)   &&
      UpperBitsNotSet(p->M_LEVELTR(k),     3)   &&
      UpperBitsNotSet(p->NID_NTC(k),       8)   &&
      UpperBitsNotSet(p->L_ACKLEVELTR(k),  15);

*/

#endif // LEVEL_TRANSITION_ORDER_H_INCLUDED

