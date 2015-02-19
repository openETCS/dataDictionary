
#ifndef TRACKTOTRAIN_HEADER_H_INCLUDED
#define TRACKTOTRAIN_HEADER_H_INCLUDED

#include "Bitstream.h"

struct TrackToTrain_Header {
    uint8_t  NID_PACKET;         // # 8
    uint16_t  L_PACKET;           // # 13
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
      Invariant(p->L_PACKET);

    predicate ZeroInitialized(TrackToTrain_Header* p) =
      ZeroInitialized(p->NID_PACKET)   &&
      ZeroInitialized(p->L_PACKET);

    predicate EqualBits(Bitstream* stream, integer pos, TrackToTrain_Header* p) =
      EqualBits(stream, pos,       pos +  8,  p->NID_PACKET)   &&
      EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET);


    predicate UpperBitsNotSet(TrackToTrain_Header* p) =
      UpperBitsNotSet(p->NID_PACKET,  8)   &&
      UpperBitsNotSet(p->L_PACKET,    13);

*/


#endif // TRACKTOTRAIN_HEADER_H_INCLUDED

