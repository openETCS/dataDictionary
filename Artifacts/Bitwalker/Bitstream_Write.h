
#ifndef BITSTREAM_WRITE_H_INCLUDED
#define BITSTREAM_WRITE_H_INCLUDED

#include "Bitstream.h"
#include "BitstreamInvariant.h"

/*@
  requires valid_stream:     \valid(stream);
  requires stream_invariant: BitstreamInvariant(stream);
  requires max_pos:          stream->bitpos + length <= UINT32_MAX;
  requires max_length:       length <= 64;

  assigns  stream->addr[0..stream->size - 1];
  assigns  stream->bitpos;

  ensures  increment: stream->bitpos == \old(stream->bitpos) + length;

  behavior  invalid_bit_sequence:
    assumes !NormalBitsequence{Pre}(stream, length);

    assigns stream->addr[0..stream->size - 1];
    assigns stream->bitpos;

    ensures result:  \result == -1;

  behavior  value_too_big:
    assumes NormalBitsequence{Pre}(stream, length) && !UpperBitsNotSet(value, length);

    assigns stream->addr[0..stream->size - 1];
    assigns stream->bitpos;

    ensures result: \result == -2;

  behavior  normal_case:
    assumes NormalBitsequence{Pre}(stream, length) && UpperBitsNotSet{Pre}(value, length);

    assigns stream->addr[0..stream->size - 1];
    assigns stream->bitpos;

    ensures left:   BitstreamUnchanged{Here,Old}(stream, 0, \old(stream->bitpos));

    ensures middle: BitstreamEqual64(stream, \old(stream->bitpos), stream->bitpos, value);

    ensures right:  BitstreamUnchanged{Here,Old}(stream, stream->bitpos, 8 * stream->size);

    ensures result: \result == 0;

    ensures BitstreamInvariant(stream);

  complete behaviors;
  disjoint behaviors;
*/
int  Bitstream_Write(Bitstream* stream, uint32_t length, uint64_t value);

#endif // BITSTREAM_WRITE_H_INCLUDED

