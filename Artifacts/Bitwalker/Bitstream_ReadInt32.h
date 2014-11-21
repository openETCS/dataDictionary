
#ifndef Bitstream_ReadInt32_included
#define Bitstream_ReadInt32_included

#include "Bitstream.h"
#include "BitstreamInvariant.h"

/*@
  requires \valid(stream);
  requires BitstreamInvariant(stream);
  requires length < 31;
  requires stream->bitposition + length <= UINT32_MAX;

  assigns  stream->bitposition;

  ensures \old(stream->bitposition) + length == stream->bitposition;

  behavior  invalid_bit_sequence:
    assumes  stream->bitposition + length  > 8 * stream->size;
    assigns  stream->bitposition;

    ensures \result == 0;

  behavior  normal_case:
    assumes  stream->bitposition + length  <= 8 * stream->size;
    assigns  stream->bitposition;

    ensures \forall integer i; 0 <= i < length ==>
    		(LeftBitInStream(\old(stream->addr), \old(stream->bitposition)+i)
            <==> LeftBit32(\result, 32-length + i));

    ensures \forall integer i; 0 <= i < 32-length ==> !LeftBit32(\result, i);

    ensures \result < (1 << length);

  complete behaviors;
  disjoint behaviors;
*/
int32_t Bitstream_ReadInt32(Bitstream* stream, uint32_t length);

#endif

