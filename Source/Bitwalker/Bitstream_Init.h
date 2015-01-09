
#ifndef BITSTREAM_INIT_H_INCLUDED
#define BITSTREAM_INIT_H_INCLUDED

#include "Bitstream.h"

/*@
  requires valid:     Writeable(stream);

  requires bit_size:  8 * size <= UINT32_MAX;

  requires valid_pos: bitpos <= 8 * size;

  requires separated: \separated(addr + (0..size-1), stream);

  assigns  stream->addr, stream->size, stream->bitpos;

  ensures  addr:      stream->addr == addr;

  ensures  size:      stream->size == size;

  ensures  bitpos:    stream->bitpos == bitpos;

  ensures  invariant: Invariant(stream, 0);
*/
void Bitstream_Init(Bitstream* stream, uint8_t* addr, uint32_t size, uint32_t bitpos);

#endif // BITSTREAM_INIT_H_INCLUDED

