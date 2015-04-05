
#ifndef BITSTREAM_READ_H_INCLUDED
#define BITSTREAM_READ_H_INCLUDED

#include "Bitstream.h"

/*@
  requires  valid:      Readable(stream);
  requires  invariant:  Invariant(stream, length);
  requires  normal:     Normal(stream, length);

  assigns  stream->bitpos;

  ensures  pos:        stream->bitpos == \old(stream->bitpos) + length;
  ensures  changed:    EqualBits(stream, \old(stream->bitpos), stream->bitpos, \result);
  ensures  upper:      UpperBitsNotSet(\result, length);
*/
uint64_t Bitstream_Read(Bitstream* stream, uint32_t length);

#endif // BITSTREAM_READ_H_INCLUDED

