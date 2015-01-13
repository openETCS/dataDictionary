
#ifndef TEMPORARY_SPEED_RESTRICTION_H_INCLUDED
#define TEMPORARY_SPEED_RESTRICTION_H_INCLUDED

#include "Bitstream.h"

struct Temporary_Speed_Restriction
{
    // TransmissionMedia=Any
    // Transmission of temporary speed restriction.
    // Packet Number = 65

    uint64_t  NID_PACKET;       // # 8
    uint64_t  Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t  Q_SCALE;          // # 2
    uint64_t  NID_TSR;          // # 8
    uint64_t  D_TSR;            // # 15
    uint64_t  L_TSR;            // # 15
    uint64_t  Q_FRONT;          // # 1
    uint64_t  V_TSR;            // # 7
};

typedef struct Temporary_Speed_Restriction Temporary_Speed_Restriction;

#define TEMPORARY_SPEED_RESTRICTION_BITSIZE 71

/*@
    logic integer BitSize{L}(Temporary_Speed_Restriction* p) = TEMPORARY_SPEED_RESTRICTION_BITSIZE;

    logic integer MaxBitSize{L}(Temporary_Speed_Restriction* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Temporary_Speed_Restriction* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Temporary_Speed_Restriction* p) =
      Invariant(p->NID_PACKET)        &&
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->NID_TSR)           &&
      Invariant(p->D_TSR)             &&
      Invariant(p->L_TSR)             &&
      Invariant(p->Q_FRONT)           &&
      Invariant(p->V_TSR);

    predicate ZeroInitialized(Temporary_Speed_Restriction* p) =
      ZeroInitialized(p->NID_PACKET)        &&
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->NID_TSR)           &&
      ZeroInitialized(p->D_TSR)             &&
      ZeroInitialized(p->L_TSR)             &&
      ZeroInitialized(p->Q_FRONT)           &&
      ZeroInitialized(p->V_TSR);

    predicate EqualBits(Bitstream* stream, integer pos, Temporary_Speed_Restriction* p) =
      EqualBits(stream, pos,       pos + 8,   p->NID_PACKET)        &&
      EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR)             &&
      EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET)          &&
      EqualBits(stream, pos + 23,  pos + 25,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 25,  pos + 33,  p->NID_TSR)           &&
      EqualBits(stream, pos + 33,  pos + 48,  p->D_TSR)             &&
      EqualBits(stream, pos + 48,  pos + 63,  p->L_TSR)             &&
      EqualBits(stream, pos + 63,  pos + 64,  p->Q_FRONT)           &&
      EqualBits(stream, pos + 64,  pos + 71,  p->V_TSR);


    predicate UpperBitsNotSet(Temporary_Speed_Restriction* p) =
      UpperBitsNotSet(p->NID_PACKET,       8)   &&
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->NID_TSR,          8)   &&
      UpperBitsNotSet(p->D_TSR,            15)  &&
      UpperBitsNotSet(p->L_TSR,            15)  &&
      UpperBitsNotSet(p->Q_FRONT,          1)   &&
      UpperBitsNotSet(p->V_TSR,            7);

*/

#endif // TEMPORARY_SPEED_RESTRICTION_H_INCLUDED

