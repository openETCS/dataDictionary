
#ifndef BITSTREAM_READ_H_INCLUDED
#define BITSTREAM_READ_H_INCLUDED

#include "Bitstream.h"

/*@
  requires valid:     Readable(stream);

  requires invariant: Invariant(stream, length);

  assigns  stream->bitpos;

  ensures  increment: stream->bitpos == \old(stream->bitpos) + length;

  behavior  normal_case:
    assumes Normal{Pre}(stream, length); // it is strange to add "Pre" here

    assigns stream->bitpos;

    ensures equal:     EqualBits(stream, \old(stream->bitpos), stream->bitpos, \result);

    ensures upper:     UpperBitsNotSet(\result, length);

    ensures unchanged: EqualBits{Here,Old}(stream, 0, 8*stream->size);

  behavior  invalid_bit_sequence:
    assumes !Normal{Pre}(stream, length);

    assigns stream->bitpos;

    ensures invalid_result: \result == 0;

  complete behaviors;
  disjoint behaviors;
*/
uint64_t Bitstream_Read(Bitstream* stream, uint32_t length);

#endif // BITSTREAM_READ_H_INCLUDED

