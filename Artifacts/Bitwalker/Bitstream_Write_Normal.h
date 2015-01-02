
#ifndef BITSTREAM_WRITE_NORMAL_H_INCLUDED
#define BITSTREAM_WRITE_NORMAL_H_INCLUDED

#include "Bitstream.h"

/*@
  requires valid:     Writeable(stream);

  requires invariant: Invariant(stream, length);

  requires normal:    Normal(stream, length);

  requires upper:     UpperBitsNotSet(value, length);

  assigns  stream->addr[0..stream->size - 1];

  ensures left:       BitstreamUnchanged{Here,Old}(stream, 0, stream->bitpos);

  ensures middle:     BitstreamEqual64(stream, stream->bitpos, stream->bitpos + length, value);

  ensures right:      BitstreamUnchanged{Here,Old}(stream, stream->bitpos + length, 8 * stream->size);
*/
void  Bitstream_Write_Normal(Bitstream* stream, uint32_t length, uint64_t value);

#endif // BITSTREAM_WRITE_NORMAL_H_INCLUDED

