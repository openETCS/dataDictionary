
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

    ensures BitstreamEqual64(stream, \old(stream->bitpos), stream->bitpos, \result, 64 - stream->bitpos);

    ensures LeftNotSet64(\result, 64 - length);

    ensures BitstreamUnchanged{Old}(stream, 0, 8*stream->size);

    ensures \result < (1 << length);

  complete behaviors;
  disjoint behaviors;
*/
uint64_t Bitstream_Read(Bitstream* stream, uint32_t length);

#endif

