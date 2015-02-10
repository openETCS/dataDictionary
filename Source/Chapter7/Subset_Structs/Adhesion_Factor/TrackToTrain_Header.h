
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

    predicate Invariant(TrackToTrain_Header* p) =
      Invariant(p->NID_PACKET)   &&
      Invariant(p->Q_DIR)        &&
      Invariant(p->L_PACKET);

    predicate ZeroInitialized(TrackToTrain_Header* p) =
      ZeroInitialized(p->NID_PACKET)   &&
      ZeroInitialized(p->Q_DIR)        &&
      ZeroInitialized(p->L_PACKET);

    predicate EqualBits(Bitstream* stream, integer pos, TrackToTrain_Header* p) =
      EqualBits(stream, pos,       pos +  2,  p->NID_PACKET)   &&
      EqualBits(stream, pos +  8,  pos + 10,  p->Q_DIR)        &&
      EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET);


    predicate UpperBitsNotSet(TrackToTrain_Header* p) =
      UpperBitsNotSet(p->NID_PACKET,  8)   &&
      UpperBitsNotSet(p->Q_DIR,       2)   &&
      UpperBitsNotSet(p->L_PACKET,    13);

*/


#endif // TRACKTOTRAIN_HEADER_H_INCLUDED

