
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
  predicate Readable{L}(Bitstream* stream) = \valid(stream) &&
         \valid_read(stream->addr + (0..stream->size-1));

  predicate Writeable{L}(Bitstream* stream) = \valid(stream) &&
         \valid(stream->addr + (0..stream->size-1));

  predicate Invariant{L}(Bitstream* stream, integer length) =
     \separated(stream, stream->addr + (0..stream->size-1)) &&
     BitwalkerInvariant{L}(stream->size, stream->bitpos, length);

  predicate Normal{L}(Bitstream* stream, integer length) =
     NormalBitwalker(stream->size, stream->bitpos, length);

  predicate LeftInBitstream{L}(Bitstream* stream, integer i) =
     \at(LeftBit8Array(stream->addr, i),L);

  predicate Unchanged{A,B}(Bitstream* stream, integer first, integer last) =
     \forall integer i;  first <= i < last ==>
        (LeftInBitstream{A}(stream, i) <==> LeftInBitstream{B}(stream, i));

  predicate Unchanged{A,B}(Bitstream* stream) =
     Unchanged{A,B}(stream, 0, \at(stream->bitpos,B)) &&
     Unchanged{A,B}(stream, \at(stream->bitpos,A), 8 * \at(stream->size,A));

  predicate EqualBits{L}(Bitstream* stream , integer length, uint64_t value) =
      EqualBits{L}(stream->addr, stream->bitpos, stream->bitpos + length, value);

*/

/*@
  requires valid:     Readable(stream);
  requires invariant: Invariant(stream, length);

  assigns \nothing;

  ensures \result <==> Normal(stream, length);
*/
int NormalBitstream(const Bitstream* stream, uint32_t length);


#endif // BITSTREAM_H_INCLUDED

