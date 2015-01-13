
#ifndef PERMITTED_BRAKING_DISTANCE_INFORMATION_H_INCLUDED
#define PERMITTED_BRAKING_DISTANCE_INFORMATION_H_INCLUDED

#include "Bitstream.h"

struct Permitted_Braking_Distance_Information
{
    // TransmissionMedia=Any
    // This packet requests the on-board calculation of speed restrictions which ensure a given permitted brake distance in case of an EB, or SB, intervention
    // Packet Number = 52

    uint64_t  NID_PACKET;       // # 8
    uint64_t  Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t  Q_SCALE;          // # 2
    uint64_t  Q_TRACKINIT;      // # 1
    uint64_t  D_TRACKINIT;      // # 15
    uint64_t  D_PBD;            // # 15
    uint64_t  Q_GDIR;           // # 1
    uint64_t  G_PBDSR;          // # 8
    uint64_t  Q_PBDSR;          // # 1
    uint64_t  D_PBDSR;          // # 15
    uint64_t  L_PBDSR;          // # 15
    uint64_t  N_ITER;           // # 5// # 15// # 1// # 8// # 1// # 15// # 15
};

typedef struct Permitted_Braking_Distance_Information Permitted_Braking_Distance_Information;

#define PERMITTED_BRAKING_DISTANCE_INFORMATION_BITSIZE 156

/*@
    logic integer BitSize{L}(Permitted_Braking_Distance_Information* p) = PERMITTED_BRAKING_DISTANCE_INFORMATION_BITSIZE;

    logic integer MaxBitSize{L}(Permitted_Braking_Distance_Information* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Permitted_Braking_Distance_Information* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Permitted_Braking_Distance_Information* p) =
      Invariant(p->NID_PACKET)        &&
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->Q_TRACKINIT)       &&
      Invariant(p->D_TRACKINIT)       &&
      Invariant(p->D_PBD)             &&
      Invariant(p->Q_GDIR)            &&
      Invariant(p->G_PBDSR)           &&
      Invariant(p->Q_PBDSR)           &&
      Invariant(p->D_PBDSR)           &&
      Invariant(p->L_PBDSR)           &&
      Invariant(p->N_ITER)            &&
      Invariant(p->D_PBD(k))          &&
      Invariant(p->Q_GDIR(k))         &&
      Invariant(p->G_PBDSR(k))        &&
      Invariant(p->Q_PBDSR(k))        &&
      Invariant(p->D_PBDSR(k))        &&
      Invariant(p->L_PBDSR(k));

    predicate ZeroInitialized(Permitted_Braking_Distance_Information* p) =
      ZeroInitialized(p->NID_PACKET)        &&
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->Q_TRACKINIT)       &&
      ZeroInitialized(p->D_TRACKINIT)       &&
      ZeroInitialized(p->D_PBD)             &&
      ZeroInitialized(p->Q_GDIR)            &&
      ZeroInitialized(p->G_PBDSR)           &&
      ZeroInitialized(p->Q_PBDSR)           &&
      ZeroInitialized(p->D_PBDSR)           &&
      ZeroInitialized(p->L_PBDSR)           &&
      ZeroInitialized(p->N_ITER)            &&
      ZeroInitialized(p->D_PBD(k))          &&
      ZeroInitialized(p->Q_GDIR(k))         &&
      ZeroInitialized(p->G_PBDSR(k))        &&
      ZeroInitialized(p->Q_PBDSR(k))        &&
      ZeroInitialized(p->D_PBDSR(k))        &&
      ZeroInitialized(p->L_PBDSR(k));

    predicate EqualBits(Bitstream* stream, integer pos, Permitted_Braking_Distance_Information* p) =
      EqualBits(stream, pos,       pos + 8,   p->NID_PACKET)        &&
      EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR)             &&
      EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET)          &&
      EqualBits(stream, pos + 23,  pos + 25,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 25,  pos + 26,  p->Q_TRACKINIT)       &&
      EqualBits(stream, pos + 26,  pos + 41,  p->D_TRACKINIT)       &&
      EqualBits(stream, pos + 41,  pos + 56,  p->D_PBD)             &&
      EqualBits(stream, pos + 56,  pos + 57,  p->Q_GDIR)            &&
      EqualBits(stream, pos + 57,  pos + 65,  p->G_PBDSR)           &&
      EqualBits(stream, pos + 65,  pos + 66,  p->Q_PBDSR)           &&
      EqualBits(stream, pos + 66,  pos + 81,  p->D_PBDSR)           &&
      EqualBits(stream, pos + 81,  pos + 96,  p->L_PBDSR)           &&
      EqualBits(stream, pos + 96,  pos + 101, p->N_ITER)            &&
      EqualBits(stream, pos + 101, pos + 116, p->D_PBD(k))          &&
      EqualBits(stream, pos + 116, pos + 117, p->Q_GDIR(k))         &&
      EqualBits(stream, pos + 117, pos + 125, p->G_PBDSR(k))        &&
      EqualBits(stream, pos + 125, pos + 126, p->Q_PBDSR(k))        &&
      EqualBits(stream, pos + 126, pos + 141, p->D_PBDSR(k))        &&
      EqualBits(stream, pos + 141, pos + 156, p->L_PBDSR(k));


    predicate UpperBitsNotSet(Permitted_Braking_Distance_Information* p) =
      UpperBitsNotSet(p->NID_PACKET,       8)   &&
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->Q_TRACKINIT,      1)   &&
      UpperBitsNotSet(p->D_TRACKINIT,      15)  &&
      UpperBitsNotSet(p->D_PBD,            15)  &&
      UpperBitsNotSet(p->Q_GDIR,           1)   &&
      UpperBitsNotSet(p->G_PBDSR,          8)   &&
      UpperBitsNotSet(p->Q_PBDSR,          1)   &&
      UpperBitsNotSet(p->D_PBDSR,          15)  &&
      UpperBitsNotSet(p->L_PBDSR,          15)  &&
      UpperBitsNotSet(p->N_ITER,           5)   &&
      UpperBitsNotSet(p->D_PBD(k),         15)  &&
      UpperBitsNotSet(p->Q_GDIR(k),        1)   &&
      UpperBitsNotSet(p->G_PBDSR(k),       8)   &&
      UpperBitsNotSet(p->Q_PBDSR(k),       1)   &&
      UpperBitsNotSet(p->D_PBDSR(k),       15)  &&
      UpperBitsNotSet(p->L_PBDSR(k),       15);

*/

#endif // PERMITTED_BRAKING_DISTANCE_INFORMATION_H_INCLUDED

