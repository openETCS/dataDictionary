
#ifndef TRACK_CONDITION_H_INCLUDED
#define TRACK_CONDITION_H_INCLUDED

#include "Bitstream.h"

struct Track_Condition
{
    // TransmissionMedia=Any
    // The packet gives details concerning the track ahead to support the driver when e.g. lower pantograph
    // Packet Number = 68

    uint64_t  NID_PACKET;       // # 8
    uint64_t  Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t  Q_SCALE;          // # 2
    uint64_t  Q_TRACKINIT;      // # 1
    uint64_t  D_TRACKINIT;      // # 15
    uint64_t  D_TRACKCOND;      // # 15
    uint64_t  L_TRACKCOND;      // # 15
    uint64_t  M_TRACKCOND;      // # 4
    uint64_t  N_ITER;           // # 5// # 15// # 15// # 4
};

typedef struct Track_Condition Track_Condition;

#define TRACK_CONDITION_BITSIZE 114

/*@
    logic integer BitSize{L}(Track_Condition* p) = TRACK_CONDITION_BITSIZE;

    logic integer MaxBitSize{L}(Track_Condition* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Track_Condition* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Track_Condition* p) =
      Invariant(p->NID_PACKET)        &&
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->Q_TRACKINIT)       &&
      Invariant(p->D_TRACKINIT)       &&
      Invariant(p->D_TRACKCOND)       &&
      Invariant(p->L_TRACKCOND)       &&
      Invariant(p->M_TRACKCOND)       &&
      Invariant(p->N_ITER)            &&
      Invariant(p->D_TRACKCOND(k))    &&
      Invariant(p->L_TRACKCOND(k))    &&
      Invariant(p->M_TRACKCOND(k));

    predicate ZeroInitialized(Track_Condition* p) =
      ZeroInitialized(p->NID_PACKET)        &&
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->Q_TRACKINIT)       &&
      ZeroInitialized(p->D_TRACKINIT)       &&
      ZeroInitialized(p->D_TRACKCOND)       &&
      ZeroInitialized(p->L_TRACKCOND)       &&
      ZeroInitialized(p->M_TRACKCOND)       &&
      ZeroInitialized(p->N_ITER)            &&
      ZeroInitialized(p->D_TRACKCOND(k))    &&
      ZeroInitialized(p->L_TRACKCOND(k))    &&
      ZeroInitialized(p->M_TRACKCOND(k));

    predicate EqualBits(Bitstream* stream, integer pos, Track_Condition* p) =
      EqualBits(stream, pos,       pos + 8,   p->NID_PACKET)        &&
      EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR)             &&
      EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET)          &&
      EqualBits(stream, pos + 23,  pos + 25,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 25,  pos + 26,  p->Q_TRACKINIT)       &&
      EqualBits(stream, pos + 26,  pos + 41,  p->D_TRACKINIT)       &&
      EqualBits(stream, pos + 41,  pos + 56,  p->D_TRACKCOND)       &&
      EqualBits(stream, pos + 56,  pos + 71,  p->L_TRACKCOND)       &&
      EqualBits(stream, pos + 71,  pos + 75,  p->M_TRACKCOND)       &&
      EqualBits(stream, pos + 75,  pos + 80,  p->N_ITER)            &&
      EqualBits(stream, pos + 80,  pos + 95,  p->D_TRACKCOND(k))    &&
      EqualBits(stream, pos + 95,  pos + 110, p->L_TRACKCOND(k))    &&
      EqualBits(stream, pos + 110, pos + 114, p->M_TRACKCOND(k));


    predicate UpperBitsNotSet(Track_Condition* p) =
      UpperBitsNotSet(p->NID_PACKET,       8)   &&
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->Q_TRACKINIT,      1)   &&
      UpperBitsNotSet(p->D_TRACKINIT,      15)  &&
      UpperBitsNotSet(p->D_TRACKCOND,      15)  &&
      UpperBitsNotSet(p->L_TRACKCOND,      15)  &&
      UpperBitsNotSet(p->M_TRACKCOND,      4)   &&
      UpperBitsNotSet(p->N_ITER,           5)   &&
      UpperBitsNotSet(p->D_TRACKCOND(k),   15)  &&
      UpperBitsNotSet(p->L_TRACKCOND(k),   15)  &&
      UpperBitsNotSet(p->M_TRACKCOND(k),   4);

*/

#endif // TRACK_CONDITION_H_INCLUDED

