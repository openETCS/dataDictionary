
#ifndef Bitstream_Read_included
#define Bitstream_Read_included

#include "Bitstream.h"
#include "BitstreamInvariant.h"

/*@
  requires \valid(stream);
  requires BitstreamInvariant(stream);
  requires length <= 64;
  requires stream->bitpos + length <= UINT32_MAX;

  assigns  stream->bitpos;

  ensures \old(stream->bitpos) + length == stream->bitpos;

  behavior  invalid_bit_sequence:
    assumes  stream->bitpos + length  > 8 * stream->size;
    assigns  stream->bitpos;

    ensures \result == 0;

  behavior  normal_case:
    assumes  stream->bitpos + length <= 8 * stream->size;
    assigns  stream->bitpos;

    ensures \forall integer i; 0 <= i < length ==>
    		(LeftBitInStream(stream->addr, \old(stream->bitpos)+i)
            <==> LeftBit64(\result, 64-length + i));

    ensures \forall integer i; 0 <= i < 64-length ==> !LeftBit64(\result, i);

    ensures \result < (1 << length);

  complete behaviors;
  disjoint behaviors;
*/
uint64_t Bitstream_Read(Bitstream* stream, uint32_t length);

#endif

