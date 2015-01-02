
#ifndef BITSTREAM_WRITE_H_INCLUDED
#define BITSTREAM_WRITE_H_INCLUDED

#include "Bitstream.h"

/*@
  requires valid:     \valid(stream);

  requires invariant: Invariant(stream);

  requires length:    length <= 64;

  requires overflow:  stream->bitpos + length <= UINT32_MAX;

  assigns  stream->addr[0..stream->size - 1];
  assigns  stream->bitpos;

  ensures  increment: stream->bitpos == \old(stream->bitpos) + length;

  behavior  normal_case:
    assumes Normal{Pre}(stream, length) && UpperBitsNotSet{Pre}(value, length);

    assigns stream->addr[0..stream->size - 1];
    assigns stream->bitpos;

    ensures left:   BitstreamUnchanged{Here,Old}(stream, 0, \old(stream->bitpos));

    ensures middle: BitstreamEqual64(stream, \old(stream->bitpos), stream->bitpos, value);

    ensures right:  BitstreamUnchanged{Here,Old}(stream, stream->bitpos, 8 * stream->size);

    ensures result: \result == 0;

    ensures Invariant(stream);

  behavior  value_too_big:
    assumes Normal{Pre}(stream, length) && !UpperBitsNotSet{Pre}(value, length);

    assigns stream->addr[0..stream->size - 1];
    assigns stream->bitpos;

    ensures result: \result == -2;

  behavior  invalid_bit_sequence:
    assumes !Normal{Pre}(stream, length);

    assigns stream->addr[0..stream->size - 1];
    assigns stream->bitpos;

    ensures result:  \result == -1;

  complete behaviors;
  disjoint behaviors;
*/
int  Bitstream_Write(Bitstream* stream, uint32_t length, uint64_t value);

#endif // BITSTREAM_WRITE_H_INCLUDED

