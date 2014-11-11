
#ifndef Bitstream_Read_included
#define Bitstream_Read_included

#include "Bitstream.h"
#include "BitstreamInvariant.h"

/*@
  requires \valid(stream);
  requires BitstreamInvariant(stream);
  requires 0 <= length <= 64;
  requires stream->bitposition + length <= UINT_MAX;

  assigns  stream->bitposition;

  ensures \old(stream->bitposition) + length == stream->bitposition;

  behavior  invalid_bit_sequence:
    assumes (stream->bitposition + length)  > 8 * stream->size;
    assigns  stream->bitposition;

    ensures \result == 0;

  behavior  normal_case:
    assumes (stream->bitposition + length) <= 8 * stream->size;
    assigns  stream->bitposition;

    ensures \forall integer i; 0 <= i < length ==>
    		(LeftBitInStream(\old(stream->addr), \old(stream->bitposition)+i) <==> LeftBit64(\result, 64-length + i));

    ensures \forall integer i; 0 <= i < 64-length ==> !LeftBit64(\result, i);

    ensures \result < (1 << length);

  complete behaviors;
  disjoint behaviors;
*/
uint64_t Bitstream_Read(Bitstream* stream, uint32_t length);

#endif

