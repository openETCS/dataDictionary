
#ifndef Bitstream_Write_included
#define Bitstream_Write_included

#include "Bitstream.h"
#include "BitstreamInvariant.h"

/*@
  requires \valid(stream);
  requires BitstreamInvariant(stream);
  requires length <= 63;
  requires stream->bitpos + length <= UINT32_MAX;

  assigns  stream->addr[0..stream->size - 1];
  assigns  stream->bitpos;

  ensures \old(stream->bitpos) + length == stream->bitpos;

  behavior  invalid_bit_sequence:
    assumes  !NormalBitsequence(stream, length);

    assigns  stream->addr[0..stream->size - 1];
    assigns  stream->bitpos;

    ensures \result == -1;

  behavior  value_too_big:
    assumes NormalBitsequence(stream, length) && (1 << length) <= value;

    assigns  stream->addr[0..stream->size - 1];
    assigns  stream->bitpos;

    ensures \result == -2;

  behavior  normal_case:
    assumes NormalBitsequence(stream, length) && value < (1 << length);

    assigns  stream->addr[0..stream->size - 1];
    assigns  stream->bitpos;

    ensures \forall integer i; 0 <= i < \old(stream->bitpos) ==>
      (LeftBitInStream(stream, i) <==> \old(LeftBitInStream(stream, i)));

    ensures \forall integer i; \old(stream->bitpos) <= i < stream->bitpos ==>
      (LeftBitInStream(stream, i) <==> LeftBit64(value, 64 - stream->bitpos + i));

    ensures \forall integer i; stream->bitpos < i < 8 * stream->size  ==>
      (LeftBitInStream(stream, i) <==> \old(LeftBitInStream(stream, i)));

    ensures \result == 0;

  complete behaviors;
  disjoint behaviors;
*/
int  Bitstream_Write(Bitstream* stream, uint32_t length, uint64_t value);

#endif

