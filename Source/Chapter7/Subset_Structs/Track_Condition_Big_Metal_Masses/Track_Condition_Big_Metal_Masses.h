
#ifndef TRACK_CONDITION_BIG_METAL_MASSES_H_INCLUDED
#define TRACK_CONDITION_BIG_METAL_MASSES_H_INCLUDED

#include "Bitstream.h"

struct Track_Condition_Big_Metal_Masses
{
    // TransmissionMedia=Balise
    // The packet gives details concerning where to ignore integrity check alarms of balise transmission due to big metal masses trackside.
    // Packet Number = 67

    uint64_t  NID_PACKET;       // # 8
    uint64_t  Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t  Q_SCALE;          // # 2
    uint64_t  D_TRACKCOND;      // # 15
    uint64_t  L_TRACKCOND;      // # 15
    uint64_t  N_ITER;           // # 5// # 15// # 15
};

typedef struct Track_Condition_Big_Metal_Masses Track_Condition_Big_Metal_Masses;

#define TRACK_CONDITION_BIG_METAL_MASSES_BITSIZE 90

/*@
    logic integer BitSize{L}(Track_Condition_Big_Metal_Masses* p) = TRACK_CONDITION_BIG_METAL_MASSES_BITSIZE;

    logic integer MaxBitSize{L}(Track_Condition_Big_Metal_Masses* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Track_Condition_Big_Metal_Masses* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Track_Condition_Big_Metal_Masses* p) =
      Invariant(p->NID_PACKET)        &&
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->D_TRACKCOND)       &&
      Invariant(p->L_TRACKCOND)       &&
      Invariant(p->N_ITER)            &&
      Invariant(p->D_TRACKCOND(k))    &&
      Invariant(p->L_TRACKCOND(k));

    predicate ZeroInitialized(Track_Condition_Big_Metal_Masses* p) =
      ZeroInitialized(p->NID_PACKET)        &&
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->D_TRACKCOND)       &&
      ZeroInitialized(p->L_TRACKCOND)       &&
      ZeroInitialized(p->N_ITER)            &&
      ZeroInitialized(p->D_TRACKCOND(k))    &&
      ZeroInitialized(p->L_TRACKCOND(k));

    predicate EqualBits(Bitstream* stream, integer pos, Track_Condition_Big_Metal_Masses* p) =
      EqualBits(stream, pos,       pos + 8,   p->NID_PACKET)        &&
      EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR)             &&
      EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET)          &&
      EqualBits(stream, pos + 23,  pos + 25,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 25,  pos + 40,  p->D_TRACKCOND)       &&
      EqualBits(stream, pos + 40,  pos + 55,  p->L_TRACKCOND)       &&
      EqualBits(stream, pos + 55,  pos + 60,  p->N_ITER)            &&
      EqualBits(stream, pos + 60,  pos + 75,  p->D_TRACKCOND(k))    &&
      EqualBits(stream, pos + 75,  pos + 90,  p->L_TRACKCOND(k));


    predicate UpperBitsNotSet(Track_Condition_Big_Metal_Masses* p) =
      UpperBitsNotSet(p->NID_PACKET,       8)   &&
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->D_TRACKCOND,      15)  &&
      UpperBitsNotSet(p->L_TRACKCOND,      15)  &&
      UpperBitsNotSet(p->N_ITER,           5)   &&
      UpperBitsNotSet(p->D_TRACKCOND(k),   15)  &&
      UpperBitsNotSet(p->L_TRACKCOND(k),   15);

*/

#endif // TRACK_CONDITION_BIG_METAL_MASSES_H_INCLUDED

