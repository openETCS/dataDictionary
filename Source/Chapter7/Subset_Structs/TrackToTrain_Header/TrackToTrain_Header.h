
#ifndef TRACKTOTRAIN_HEADER_H_INCLUDED
#define TRACKTOTRAIN_HEADER_H_INCLUDED

#include "Bitstream.h"

struct TrackToTrain_Header {
    uint64_t  NID_PACKET;         // # 8
    uint64_t  Q_DIR;              // # 2
    uint64_t  L_PACKET;           // # 13
};

typedef struct TrackToTrain_Header TrackToTrain_Header;

#define TRACKTOTRAIN_HEADER_BITSIZE 23

/*@
    logic integer BitSize{L}(TrackToTrain_Header* p) = TRACKTOTRAIN_HEADER_BITSIZE;

    logic integer MaxBitSize{L}(TrackToTrain_Header* p) = BitSize(p);

    predicate Separated(Bitstream* stream, TrackToTrain_Header* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invraiant(TrackToTrain_Header* p) =
      Invariant(p->NID_PACKET)       &&
      Invariant(p->Q_DIR)            &&
      Invariant(L_PACKET);

    predicate ZeroInitialized(TrackToTrain_Header* p) =
      ZeroInitialized(p->NID_PACKET)       &&
      ZeroInitialized(p->Q_DIR)            &&
      ZeroInitialized(p->L_PACKET);

    predicate EqualBits(Bitstream* stream, integer pos, TrackToTrain_Header* p) =
      EqualBits(p->NID_PACKET,    8)   &&
      EqualBits(p->Q_DIR,         2)   &&
      EqualBits(p->L_PACKET,      13)  &&

    predicate UpperBitsNotSet(TrackToTrain_Header* p) =
      UpperBitsNotSet(p->NID_PACKET,    8)   &&
      UpperBitsNotSet(p->Q_DIR,         2)   &&
      UpperBitsNotSet(P->L_PACKET,      12);

*/

#endif // TRACKTOTRAIN_HEADER_H_INCLUDED

