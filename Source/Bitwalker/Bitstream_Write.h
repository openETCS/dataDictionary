
#ifndef BITSTREAM_WRITE_H_INCLUDED
#define BITSTREAM_WRITE_H_INCLUDED

#include "Bitstream.h"

/*@
  requires valid:      Writeable(stream);
  requires invariant:  Invariant(stream, length);
  requires normal:     Normal(stream, length);
  requires upper:      UpperBitsNotSet(value, length);

  assigns stream->addr[0..stream->size - 1];
  assigns stream->bitpos;

  ensures  pos:        stream->bitpos == \at(stream->bitpos,Old) + length;
  ensures  unchanged:  Unchanged{Here,Old}(stream);
  ensures  changed:    EqualBits(stream, length, value);
*/
void Bitstream_Write(Bitstream* stream, uint32_t length, uint64_t value);

#endif // BITSTREAM_WRITE_H_INCLUDED

