
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
    assumes  !NormalBitsequence(stream, length);

    assigns  stream->bitpos;

    ensures \result == 0;

  behavior  normal_case:
    assumes  NormalBitsequence(stream, length);

    assigns  stream->bitpos;

    ensures \forall integer i; \old(stream->bitpos) <= i < stream->bitpos ==>
      (LeftBitInStream(stream, i) <==> LeftBit64(\result, 64 - stream->bitpos + i));

    ensures \forall integer i; 0 <= i < 64-length ==> !LeftBit64(\result, i);

    ensures \forall integer i; 0 <= i < 8 * stream->size ==>
      (LeftBitInStream(stream, i) <==> \old(LeftBitInStream(stream, i)));

    ensures \result < (1 << length);

  complete behaviors;
  disjoint behaviors;
*/
uint64_t Bitstream_Read(Bitstream* stream, uint32_t length);

#endif

