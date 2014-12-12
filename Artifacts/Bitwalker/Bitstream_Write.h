
#ifndef Bitstream_Write_included
#define Bitstream_Write_included

#include "Bitstream.h"
#include "BitstreamInvariant.h"

/*@
  requires valid_stream:     \valid(stream);
  requires stream_invariant: BitstreamInvariant(stream);
  requires max_pos:          stream->bitpos + length <= UINT32_MAX;
  requires max_length:       length <= 64;

  assigns  stream->addr[0..stream->size - 1];
  assigns  stream->bitpos;

  ensures \old(stream->bitpos) + length == stream->bitpos;

  behavior  invalid_bit_sequence:
    assumes  !NormalBitsequence(stream, length);

    assigns  stream->addr[0..stream->size - 1];
    assigns  stream->bitpos;

    ensures valid_result:  \result == -1;

  behavior  value_too_big:
    assumes NormalBitsequence(stream, length) && (1 << length) <= value && (length < 64);

    assigns  stream->addr[0..stream->size - 1];
    assigns  stream->bitpos;

    ensures wrong_value_result: \result == -2;

  behavior  normal_case:
    assumes NormalBitsequence(stream, length) && (value < (1 << length) || length == 64);

    assigns  stream->addr[0..stream->size - 1];
    assigns  stream->bitpos;

    ensures unchanged_left:  BitstreamUnchanged{Old}(stream, 0, \old(stream->bitpos));

    ensures copied:          BitstreamEqual64(stream, \old(stream->bitpos), stream->bitpos, value);

    ensures unchanged_right: BitstreamUnchanged{Old}(stream, stream->bitpos, 8 * stream->size);

    ensures valid_result:    \result == 0;

  complete behaviors;
  disjoint behaviors;
*/
int  Bitstream_Write(Bitstream* stream, uint32_t length, uint64_t value);

#endif

