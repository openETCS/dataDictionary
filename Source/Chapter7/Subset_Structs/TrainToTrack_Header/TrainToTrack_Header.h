
#ifndef TRAINTOTRACK_HEADER_H_INCLUDED
#define TRAINTOTRACK_HEADER_H_INCLUDED

#include "Bitstream.h"

struct TrainToTrack_Header {
    uint64_t  NID_PACKET;         // # 8
    uint64_t  Q_DIR;              // # 2
    uint64_t  L_PACKET;           // # 13
};

typedef struct TrainToTrack_Header TrainToTrack_Header;

#define TRAINTOTRACK_HEADER_BITSIZE 23

/*@
    logic integer BitSize{L}(TrainToTrack_Header* p) = TRAINTOTRACK_HEADER_BITSIZE;

    logic integer MaxBitSize{L}(TrainToTrack_Header* p) = BitSize(p);

    predicate Separated(Bitstream* stream, TrainToTrack_Header* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invraiant(TrainToTrack_Header* p) =
      Invariant(p->NID_PACKET)       &&
      Invariant(p->Q_DIR)            &&
      Invariant(L_PACKET);

    predicate ZeroInitialized(TrainToTrack_Header* p) =
      ZeroInitialized(p->NID_PACKET)       &&
      ZeroInitialized(p->Q_DIR)            &&
      ZeroInitialized(p->L_PACKET);

    predicate EqualBits(Bitstream* stream, integer pos, TrainToTrack_Header* p) =
      EqualBits(p->NID_PACKET,    8)   &&
      EqualBits(p->Q_DIR,         2)   &&
      EqualBits(p->L_PACKET,      13)  &&

    predicate UpperBitsNotSet(TrainToTrack_Header* p) =
      UpperBitsNotSet(p->NID_PACKET,    8)   &&
      UpperBitsNotSet(p->Q_DIR,         2)   &&
      UpperBitsNotSet(P->L_PACKET,      12);

*/

#endif // TRAINTOTRACK_HEADER_H_INCLUDED

