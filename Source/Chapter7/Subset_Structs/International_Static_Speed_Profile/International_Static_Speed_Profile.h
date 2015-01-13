
#ifndef INTERNATIONAL_STATIC_SPEED_PROFILE_H_INCLUDED
#define INTERNATIONAL_STATIC_SPEED_PROFILE_H_INCLUDED

#include "Bitstream.h"

struct International_Static_Speed_Profile
{
    // TransmissionMedia=Any
    // Static speed profile and optionally speed limits depending on the international train category.
    // Packet Number = 27

    uint64_t  NID_PACKET;       // # 8
    uint64_t  Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t  Q_SCALE;          // # 2
    uint64_t  D_STATIC;         // # 15
    uint64_t  V_STATIC;         // # 7
    uint64_t  Q_FRONT;          // # 1
    uint64_t  N_ITER;           // # 5// # 2// # 4// # 4// # 7
    uint64_t  N_ITER;           // # 5// # 15// # 7// # 1// # 5// # 2// # 4// # 4// # 7
};

typedef struct International_Static_Speed_Profile International_Static_Speed_Profile;

#define INTERNATIONAL_STATIC_SPEED_PROFILE_BITSIZE 120

/*@
    logic integer BitSize{L}(International_Static_Speed_Profile* p) = INTERNATIONAL_STATIC_SPEED_PROFILE_BITSIZE;

    logic integer MaxBitSize{L}(International_Static_Speed_Profile* p) = BitSize(p);

    predicate Separated(Bitstream* stream, International_Static_Speed_Profile* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(International_Static_Speed_Profile* p) =
      Invariant(p->NID_PACKET)        &&
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->D_STATIC)          &&
      Invariant(p->V_STATIC)          &&
      Invariant(p->Q_FRONT)           &&
      Invariant(p->N_ITER)            &&
      Invariant(p->Q_DIFF(n))         &&
      Invariant(p->NC_CDDIFF(n))      &&
      Invariant(p->NC_DIFF(n))        &&
      Invariant(p->V_DIFF(n))         &&
      Invariant(p->N_ITER)            &&
      Invariant(p->D_STATIC(k))       &&
      Invariant(p->V_STATIC(k))       &&
      Invariant(p->Q_FRONT(k))        &&
      Invariant(p->N_ITER(k))         &&
      Invariant(p->Q_DIFF(k,m))       &&
      Invariant(p->NC_CDDIFF(k,m))    &&
      Invariant(p->NC_DIFF(k,m))      &&
      Invariant(p->V_DIFF(k,m));

    predicate ZeroInitialized(International_Static_Speed_Profile* p) =
      ZeroInitialized(p->NID_PACKET)        &&
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->D_STATIC)          &&
      ZeroInitialized(p->V_STATIC)          &&
      ZeroInitialized(p->Q_FRONT)           &&
      ZeroInitialized(p->N_ITER)            &&
      ZeroInitialized(p->Q_DIFF(n))         &&
      ZeroInitialized(p->NC_CDDIFF(n))      &&
      ZeroInitialized(p->NC_DIFF(n))        &&
      ZeroInitialized(p->V_DIFF(n))         &&
      ZeroInitialized(p->N_ITER)            &&
      ZeroInitialized(p->D_STATIC(k))       &&
      ZeroInitialized(p->V_STATIC(k))       &&
      ZeroInitialized(p->Q_FRONT(k))        &&
      ZeroInitialized(p->N_ITER(k))         &&
      ZeroInitialized(p->Q_DIFF(k,m))       &&
      ZeroInitialized(p->NC_CDDIFF(k,m))    &&
      ZeroInitialized(p->NC_DIFF(k,m))      &&
      ZeroInitialized(p->V_DIFF(k,m));

    predicate EqualBits(Bitstream* stream, integer pos, International_Static_Speed_Profile* p) =
      EqualBits(stream, pos,       pos + 8,   p->NID_PACKET)        &&
      EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR)             &&
      EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET)          &&
      EqualBits(stream, pos + 23,  pos + 25,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 25,  pos + 40,  p->D_STATIC)          &&
      EqualBits(stream, pos + 40,  pos + 47,  p->V_STATIC)          &&
      EqualBits(stream, pos + 47,  pos + 48,  p->Q_FRONT)           &&
      EqualBits(stream, pos + 48,  pos + 53,  p->N_ITER)            &&
      EqualBits(stream, pos + 53,  pos + 55,  p->Q_DIFF(n))         &&
      EqualBits(stream, pos + 55,  pos + 59,  p->NC_CDDIFF(n))      &&
      EqualBits(stream, pos + 59,  pos + 63,  p->NC_DIFF(n))        &&
      EqualBits(stream, pos + 63,  pos + 70,  p->V_DIFF(n))         &&
      EqualBits(stream, pos + 70,  pos + 75,  p->N_ITER)            &&
      EqualBits(stream, pos + 75,  pos + 90,  p->D_STATIC(k))       &&
      EqualBits(stream, pos + 90,  pos + 97,  p->V_STATIC(k))       &&
      EqualBits(stream, pos + 97,  pos + 98,  p->Q_FRONT(k))        &&
      EqualBits(stream, pos + 98,  pos + 103, p->N_ITER(k))         &&
      EqualBits(stream, pos + 103, pos + 105, p->Q_DIFF(k,m))       &&
      EqualBits(stream, pos + 105, pos + 109, p->NC_CDDIFF(k,m))    &&
      EqualBits(stream, pos + 109, pos + 113, p->NC_DIFF(k,m))      &&
      EqualBits(stream, pos + 113, pos + 120, p->V_DIFF(k,m));


    predicate UpperBitsNotSet(International_Static_Speed_Profile* p) =
      UpperBitsNotSet(p->NID_PACKET,       8)   &&
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->D_STATIC,         15)  &&
      UpperBitsNotSet(p->V_STATIC,         7)   &&
      UpperBitsNotSet(p->Q_FRONT,          1)   &&
      UpperBitsNotSet(p->N_ITER,           5)   &&
      UpperBitsNotSet(p->Q_DIFF(n),        2)   &&
      UpperBitsNotSet(p->NC_CDDIFF(n),     4)   &&
      UpperBitsNotSet(p->NC_DIFF(n),       4)   &&
      UpperBitsNotSet(p->V_DIFF(n),        7)   &&
      UpperBitsNotSet(p->N_ITER,           5)   &&
      UpperBitsNotSet(p->D_STATIC(k),      15)  &&
      UpperBitsNotSet(p->V_STATIC(k),      7)   &&
      UpperBitsNotSet(p->Q_FRONT(k),       1)   &&
      UpperBitsNotSet(p->N_ITER(k),        5)   &&
      UpperBitsNotSet(p->Q_DIFF(k,m),      2)   &&
      UpperBitsNotSet(p->NC_CDDIFF(k,m),   4)   &&
      UpperBitsNotSet(p->NC_DIFF(k,m),     4)   &&
      UpperBitsNotSet(p->V_DIFF(k,m),      7);

*/

#endif // INTERNATIONAL_STATIC_SPEED_PROFILE_H_INCLUDED

