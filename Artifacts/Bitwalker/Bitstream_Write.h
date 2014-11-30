
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

    ensures BitstreamUnchanged{Old}(stream, 0, \old(stream->bitpos));

    ensures BitstreamEqual64(stream, \old(stream->bitpos), stream->bitpos, value);

    ensures BitstreamUnchanged{Old}(stream, stream->bitpos, 8 * stream->size);

    ensures \result == 0;

  complete behaviors;
  disjoint behaviors;
*/
int  Bitstream_Write(Bitstream* stream, uint32_t length, uint64_t value);

#endif

