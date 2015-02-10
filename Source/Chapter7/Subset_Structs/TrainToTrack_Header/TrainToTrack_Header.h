
#ifndef TRAINTOTRACK_HEADER_H_INCLUDED
#define TRAINTOTRACK_HEADER_H_INCLUDED

#include "Bitstream.h"

struct TrainToTrack_Header
{
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

    predicate Invariant(TrainToTrack_Header* p) =
      Invariant(p->NID_PACKET)       &&
      Invariant(p->Q_DIR)            &&
      Invariant(p->L_PACKET);

    predicate ZeroInitialized(TrainToTrack_Header* p) =
      ZeroInitialized(p->NID_PACKET)       &&
      ZeroInitialized(p->Q_DIR)            &&
      ZeroInitialized(p->L_PACKET);

    predicate EqualBits(Bitstream* stream, integer pos, TrainToTrack_Header* p) =
      EqualBits(stream, pos, pos + 8, p->NID_PACKET)   &&
      EqualBits(stream, pos + 8, pos + 10, p->Q_DIR)   &&
      EqualBits(stream, pos + 10, pos + 23, p->L_PACKET);

    predicate UpperBitsNotSet(TrainToTrack_Header* p) =
      UpperBitsNotSet(p->NID_PACKET,    8)   &&
      UpperBitsNotSet(p->Q_DIR,         2)   &&
      UpperBitsNotSet(p->L_PACKET,      12);

*/

#endif // TRAINTOTRACK_HEADER_H_INCLUDED

