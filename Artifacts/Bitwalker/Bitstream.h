
#ifndef BITSTREAM_H_INCLUDED
#define BITSTREAM_H_INCLUDED

#include "Bitwalker.h"

struct Bitstream
{
    uint8_t*  addr;
    uint32_t  size;
    uint32_t  bitpos;
};

typedef struct Bitstream Bitstream;

/*@
  predicate Invariant{L}(Bitstream* stream) =
     \valid(stream->addr + (0..stream->size-1))  &&
     \separated(stream, stream->addr + (0..stream->size-1)) &&
     8 * stream->size <= UINT32_MAX;

  predicate Normal{L}(Bitstream* stream, integer length) =
     stream->bitpos + length <= 8 * stream->size;

  predicate LeftInBitstream{L}(Bitstream* stream, integer i) =
     \at(LeftBit8Array(stream->addr, i),L);

  predicate BitstreamUnchanged{A,B}(Bitstream* stream, integer first, integer last) =
     \forall integer i; first <= i < last ==>
        (LeftInBitstream{A}(stream, i) <==> LeftInBitstream{B}(stream, i));

  predicate BitstreamEqual64{L}(Bitstream* stream ,
             integer first, integer last, uint64_t value) =
                EqualBits64(stream->addr, first, last, value);

*/


#endif // BITSTREAM_H_INCLUDED

