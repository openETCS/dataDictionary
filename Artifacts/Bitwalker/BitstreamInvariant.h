
#ifndef BitstreamInvariant_h
#define BitstreamInvariant_h

#include "Bitstream.h"

/*@
  predicate BitstreamInvariant(Bitstream* stream) =
     \valid(stream->addr + (0..stream->size-1))  &&
     8 * stream->size <= UINT32_MAX     &&
     \separated(stream->addr + (0..stream->size-1), stream);

  predicate NormalBitsequence(Bitstream* stream, uint32_t length) =
     stream->bitpos + length <= 8 * stream->size;

  predicate LeftBitInStream{L}(Bitstream* stream, integer i) =
                LeftBit8Array(stream->addr, i);

  predicate BitstreamUnchanged{L}(Bitstream* stream, integer first, integer last) =
   \forall integer i; first <= i < last ==>
      (LeftBitInStream(stream, i) <==> \at(LeftBitInStream(stream, i), L));

  predicate BitstreamEqual64{L}(Bitstream* stream , integer first, integer last,
                                uint64_t value, integer to) = 
    \forall integer i; first <= i < last ==>
      (LeftBitInStream(stream, i) <==> LeftBit64(value, to + i));

*/

#endif

