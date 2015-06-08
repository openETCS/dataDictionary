
#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include "Bitstream.h"

struct Header
{
    uint8_t  NID_PACKET;         // # 8
};

typedef struct Header Header;

#define HEADER_BITSIZE 8

/*@
    logic integer BitSize{L}(Header* p) = HEADER_BITSIZE;

    logic integer MaxBitSize{L}(Header* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Header* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Header* p) =
      Invariant(p->NID_PACKET);

    predicate ZeroInitialized(Header* p) =
      ZeroInitialized(p->NID_PACKET);

    predicate EqualBits(Bitstream* stream, integer pos, Header* p) =
      EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);


    predicate UpperBitsNotSet(Header* p) =
      UpperBitsNotSet(p->NID_PACKET,  8);

*/


#endif // HEADER_H_INCLUDED

