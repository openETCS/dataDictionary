
#ifndef BOTHWAYS_HEADER_H_INCLUDED
#define BOTHWAYS_HEADER_H_INCLUDED

#include "Bitstream.h"

struct BothWays_Header
{
    uint64_t  NID_PACKET;         // # 8
};

typedef struct BothWays_Header BothWays_Header;

#define BOTHWAYS_HEADER_BITSIZE 8

/*@
    logic integer BitSize{L}(BothWays_Header* p) = BOTHWAYS_HEADER_BITSIZE;

    logic integer MaxBitSize{L}(BothWays_Header* p) = BitSize(p);

    predicate Separated(Bitstream* stream, BothWays_Header* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(BothWays_Header* p) =
      Invariant(p->NID_PACKET);

    predicate ZeroInitialized(BothWays_Header* p) =
      ZeroInitialized(p->NID_PACKET);

    predicate EqualBits(Bitstream* stream, integer pos, BothWays_Header* p) =
      EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);


    predicate UpperBitsNotSet(BothWays_Header* p) =
      UpperBitsNotSet(p->NID_PACKET,  8);

*/


#endif // BOTHWAYS_HEADER_H_INCLUDED

