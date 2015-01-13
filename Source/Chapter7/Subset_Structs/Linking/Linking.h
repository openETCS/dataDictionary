
#ifndef LINKING_H_INCLUDED
#define LINKING_H_INCLUDED

#include "Bitstream.h"

struct Linking
{
    // TransmissionMedia=Any
    // Linking Information.
    // Packet Number = 5

    uint64_t  NID_PACKET;       // # 8
    uint64_t  Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t  Q_SCALE;          // # 2
    uint64_t  D_LINK;           // # 15
    uint64_t  Q_NEWCOUNTRY;     // # 1
    uint64_t  NID_C;            // # 10
    uint64_t  NID_BG;           // # 14
    uint64_t  Q_LINKORIENTATION;// # 1
    uint64_t  Q_LINKREACTION;   // # 2
    uint64_t  Q_LOCACC;         // # 6
    uint64_t  N_ITER;           // # 5// # 15// # 1// # 10// # 14// # 1// # 2// # 6
};

typedef struct Linking Linking;

#define LINKING_BITSIZE 128

/*@
    logic integer BitSize{L}(Linking* p) = LINKING_BITSIZE;

    logic integer MaxBitSize{L}(Linking* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Linking* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Linking* p) =
      Invariant(p->NID_PACKET)        &&
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->D_LINK)            &&
      Invariant(p->Q_NEWCOUNTRY)      &&
      Invariant(p->NID_C)             &&
      Invariant(p->NID_BG)            &&
      Invariant(p->Q_LINKORIENTATION) &&
      Invariant(p->Q_LINKREACTION)    &&
      Invariant(p->Q_LOCACC)          &&
      Invariant(p->N_ITER)            &&
      Invariant(p->D_LINK_(k))        &&
      Invariant(p->Q_NEWCOUNTRY(k))   &&
      Invariant(p->NID_C_(k))         &&
      Invariant(p->NID_BG_(k))        &&
      Invariant(p->Q_LINKORIENTATION_(k)) &&
      Invariant(p->Q_LINKREACTION_(k)) &&
      Invariant(p->Q_LOCACC_(k));

    predicate ZeroInitialized(Linking* p) =
      ZeroInitialized(p->NID_PACKET)        &&
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->D_LINK)            &&
      ZeroInitialized(p->Q_NEWCOUNTRY)      &&
      ZeroInitialized(p->NID_C)             &&
      ZeroInitialized(p->NID_BG)            &&
      ZeroInitialized(p->Q_LINKORIENTATION) &&
      ZeroInitialized(p->Q_LINKREACTION)    &&
      ZeroInitialized(p->Q_LOCACC)          &&
      ZeroInitialized(p->N_ITER)            &&
      ZeroInitialized(p->D_LINK_(k))        &&
      ZeroInitialized(p->Q_NEWCOUNTRY(k))   &&
      ZeroInitialized(p->NID_C_(k))         &&
      ZeroInitialized(p->NID_BG_(k))        &&
      ZeroInitialized(p->Q_LINKORIENTATION_(k)) &&
      ZeroInitialized(p->Q_LINKREACTION_(k)) &&
      ZeroInitialized(p->Q_LOCACC_(k));

    predicate EqualBits(Bitstream* stream, integer pos, Linking* p) =
      EqualBits(stream, pos,       pos + 8,   p->NID_PACKET)        &&
      EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR)             &&
      EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET)          &&
      EqualBits(stream, pos + 23,  pos + 25,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 25,  pos + 40,  p->D_LINK)            &&
      EqualBits(stream, pos + 40,  pos + 41,  p->Q_NEWCOUNTRY)      &&
      EqualBits(stream, pos + 41,  pos + 51,  p->NID_C)             &&
      EqualBits(stream, pos + 51,  pos + 65,  p->NID_BG)            &&
      EqualBits(stream, pos + 65,  pos + 66,  p->Q_LINKORIENTATION) &&
      EqualBits(stream, pos + 66,  pos + 68,  p->Q_LINKREACTION)    &&
      EqualBits(stream, pos + 68,  pos + 74,  p->Q_LOCACC)          &&
      EqualBits(stream, pos + 74,  pos + 79,  p->N_ITER)            &&
      EqualBits(stream, pos + 79,  pos + 94,  p->D_LINK_(k))        &&
      EqualBits(stream, pos + 94,  pos + 95,  p->Q_NEWCOUNTRY(k))   &&
      EqualBits(stream, pos + 95,  pos + 105, p->NID_C_(k))         &&
      EqualBits(stream, pos + 105, pos + 119, p->NID_BG_(k))        &&
      EqualBits(stream, pos + 119, pos + 120, p->Q_LINKORIENTATION_(k)) &&
      EqualBits(stream, pos + 120, pos + 122, p->Q_LINKREACTION_(k)) &&
      EqualBits(stream, pos + 122, pos + 128, p->Q_LOCACC_(k));


    predicate UpperBitsNotSet(Linking* p) =
      UpperBitsNotSet(p->NID_PACKET,       8)   &&
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->D_LINK,           15)  &&
      UpperBitsNotSet(p->Q_NEWCOUNTRY,     1)   &&
      UpperBitsNotSet(p->NID_C,            10)  &&
      UpperBitsNotSet(p->NID_BG,           14)  &&
      UpperBitsNotSet(p->Q_LINKORIENTATION,1)   &&
      UpperBitsNotSet(p->Q_LINKREACTION,   2)   &&
      UpperBitsNotSet(p->Q_LOCACC,         6)   &&
      UpperBitsNotSet(p->N_ITER,           5)   &&
      UpperBitsNotSet(p->D_LINK_(k),       15)  &&
      UpperBitsNotSet(p->Q_NEWCOUNTRY(k),  1)   &&
      UpperBitsNotSet(p->NID_C_(k),        10)  &&
      UpperBitsNotSet(p->NID_BG_(k),       14)  &&
      UpperBitsNotSet(p->Q_LINKORIENTATION_(k),1)   &&
      UpperBitsNotSet(p->Q_LINKREACTION_(k),2)   &&
      UpperBitsNotSet(p->Q_LOCACC_(k),     6);

*/

#endif // LINKING_H_INCLUDED

