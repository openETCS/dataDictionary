
#ifndef PokeNext_included
#define PokeNext_included

#include "Bitstream.h"
#include "BitstreamInvariant.h"

/*@
  requires \valid(stream);
  requires BitstreamInvariant(stream);
  requires 0 <= length <= 63;
  requires stream->bitposition + length <= UINT_MAX;

  assigns  stream->addr[0..stream->size - 1], stream->bitposition;

  ensures \old(stream->bitposition) + length == stream->bitposition;

  behavior  invalid_bit_sequence:
    assumes (stream->bitposition + length) > 8 * stream->size;

    ensures \old(stream->bitposition) + length == stream->bitposition;
    ensures \result == -1;

  behavior  value_too_big:
    assumes (1 << length) <= value && (stream->bitposition + length) <= 8 * stream->size;

    ensures \old(stream->bitposition) + length == stream->bitposition;
    ensures \result == -2;

  behavior  normal_case:
    assumes value < (1 << length) && (stream->bitposition + length) <= 8 * stream->size;

    assigns  stream->addr[0..stream->size - 1], stream->bitposition;

    ensures \forall integer i; 0 <= i < \old(stream->bitposition) ==>
    		(LeftBitInStream(stream->addr, i) <==> \old(LeftBitInStream(stream->addr, i)));

    ensures \forall integer i; stream->bitposition < i < 8 * stream->size  ==>
    		(LeftBitInStream(stream->addr, i) <==> \old(LeftBitInStream(stream->addr, i)));

    ensures \forall integer i; 0 <= i < length ==>
    		(LeftBitInStream(stream->addr, \old(stream->bitposition)+i) <==> LeftBit64(value, (64-length)+i));

    ensures \result == 0;

  complete behaviors;
  disjoint behaviors;
*/
int  Bitstream_Poke(Bitstream* stream, uint32_t length, uint64_t value);

#endif

