
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

  predicate LeftBitInSequence{L}(Bitstream* stream, integer i) =
                LeftBit8Array(stream->addr, \at(stream->bitpos,L) + i);

*/

#endif

