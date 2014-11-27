
#ifndef Bitstream_Write_included
#define Bitstream_Write_included

#include "Bitstream.h"
#include "BitstreamInvariant.h"

/*@
  requires \valid(stream);
  requires BitstreamInvariant(stream);
  requires length <= 63;
  requires stream->bitpos + length <= UINT32_MAX;

  assigns  stream->addr[0..stream->size - 1], stream->bitpos;

  ensures \old(stream->bitpos) + length == stream->bitpos;

  behavior  invalid_bit_sequence:
    assumes  stream->bitpos + length > 8 * stream->size;

    ensures \old(stream->bitpos) + length == stream->bitpos;
    ensures \result == -1;

  behavior  value_too_big:
    assumes (1 << length) <= value && stream->bitpos + length <= 8 * stream->size;

    ensures \old(stream->bitpos) + length == stream->bitpos;
    ensures \result == -2;

  behavior  normal_case:
    assumes value < (1 << length) && stream->bitpos + length <= 8 * stream->size;

    assigns  stream->addr[0..stream->size - 1], stream->bitpos;

    ensures \forall integer i; 0 <= i < \old(stream->bitpos) ==>
    		(LeftBitInStream(stream->addr, i) <==> \old(LeftBitInStream(stream->addr, i)));

    ensures \forall integer i; stream->bitpos < i < 8 * stream->size  ==>
    		(LeftBitInStream(stream->addr, i) <==> \old(LeftBitInStream(stream->addr, i)));

    ensures \forall integer i; 0 <= i < length ==>
    		(LeftBitInStream(stream->addr, \old(stream->bitpos)+i)
            <==> LeftBit64(value, (64-length)+i));

    ensures \result == 0;

  complete behaviors;
  disjoint behaviors;
*/
int  Bitstream_Write(Bitstream* stream, uint32_t length, uint64_t value);

#endif

