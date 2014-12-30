
#ifndef BITSTREAM_WRITE_NORMAL_H_INCLUDED
#define BITSTREAM_WRITE_NORMAL_H_INCLUDED

#include "Bitstream.h"

/*@
  requires valid:        \valid(stream);
  requires invariant:    Invariant(stream);
  requires max_length:   length <= 64;
  requires normal:       Normal(stream, length);
  requires not_set:      UpperBitsNotSet(value, length);

  assigns  stream->addr[0..stream->size - 1];
  assigns  stream->bitpos;

  ensures left:      BitstreamUnchanged{Here,Old}(stream, 0, \old(stream->bitpos));

  ensures middle:    BitstreamEqual64(stream, \old(stream->bitpos), stream->bitpos, value);

  ensures right:     BitstreamUnchanged{Here,Old}(stream, stream->bitpos, 8 * stream->size);

  ensures increment: stream->bitpos == \old(stream->bitpos) + length;

  ensures size:      stream->size == \old(stream->size);

  ensures invariant: Invariant(stream);
*/
void  Bitstream_Write_Normal(Bitstream* stream, uint32_t length, uint64_t value);

#endif // BITSTREAM_WRITE_NORMAL_H_INCLUDED

