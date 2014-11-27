
#ifndef Bitstream_ReadInt32_included
#define Bitstream_ReadInt32_included

#include "Bitstream.h"
#include "BitstreamInvariant.h"

/*@
  requires \valid(stream);
  requires BitstreamInvariant(stream);
  requires length < 31;
  requires stream->bitpos + length <= UINT32_MAX;

  assigns  stream->bitpos;

  ensures \old(stream->bitpos) + length == stream->bitpos;

  behavior  invalid_bit_sequence:
    assumes  stream->bitpos + length  > 8 * stream->size;
    assigns  stream->bitpos;

    ensures \result == 0;

  behavior  normal_case:
    assumes  stream->bitpos + length  <= 8 * stream->size;
    assigns  stream->bitpos;

    ensures \forall integer i; 0 <= i < length ==>
    		(LeftBitInStream(\old(stream->addr), \old(stream->bitpos)+i)
            <==> LeftBit32(\result, 32-length + i));

    ensures \forall integer i; 0 <= i < 32-length ==> !LeftBit32(\result, i);

    ensures \result < (1 << length);

  complete behaviors;
  disjoint behaviors;
*/
int32_t Bitstream_ReadInt32(Bitstream* stream, uint32_t length);

#endif

