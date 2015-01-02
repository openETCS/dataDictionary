
#ifndef BITSTREAM_READ_NORMAL_H_INCLUDED
#define BITSTREAM_READ_NORMAL_H_INCLUDED

#include "Bitstream.h"

/*@
  requires valid:      \valid(stream);

  requires invariant:  Invariant(stream);

  requires length:     length <= 64;

  requires normal:     Normal(stream, length);

  assigns  stream->bitpos;

  ensures copied:    BitstreamEqual64(stream, \old(stream->bitpos), stream->bitpos, \result);

  ensures not_set:   UpperBitsNotSet(\result, length);

  ensures unchanged: BitstreamUnchanged{Here,Old}(stream, 0, 8*stream->size);

  ensures increment: stream->bitpos == \old(stream->bitpos) + length;

  ensures size:      stream->size == \old(stream->size);

  ensures invariant: Invariant(stream);
*/
uint64_t Bitstream_Read_Normal(Bitstream* stream, uint32_t length);

#endif // BITSTREAM_READ_NORMAL_H_INCLUDED

