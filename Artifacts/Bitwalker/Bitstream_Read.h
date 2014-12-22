
#ifndef BITSTREAM_READ_H_INCLUDED
#define BITSTREAM_READ_H_INCLUDED

#include "Bitstream.h"
#include "BitstreamInvariant.h"

/*@
  requires valid_stream:     \valid(stream);
  requires stream_invariant: BitstreamInvariant(stream);
  requires max_pos:          stream->bitpos + length <= UINT32_MAX;
  requires max_length:       length <= 64;

  assigns  stream->bitpos;

  ensures  increment: stream->bitpos == \old(stream->bitpos) + length;

  behavior  invalid_bit_sequence:
    assumes  !NormalBitsequence(stream, length);

    assigns  stream->bitpos;

    ensures invalid_result: \result == 0;

  behavior  normal_case:
    assumes  NormalBitsequence{Pre}(stream, length);

    assigns  stream->bitpos;

    ensures copied:       BitstreamEqual64(stream, \old(stream->bitpos), stream->bitpos, \result);

    ensures not_set:      UpperBitsNotSet(\result, length);

    ensures unchanged:    BitstreamUnchanged{Old}(stream, 0, 8*stream->size);

  complete behaviors;
  disjoint behaviors;
*/
uint64_t Bitstream_Read(Bitstream* stream, uint32_t length);

#endif // BITSTREAM_READ_H_INCLUDED

