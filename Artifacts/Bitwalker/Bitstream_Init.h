
#ifndef BITSTREAM_INIT_H_INCLUDED
#define BITSTREAM_INIT_H_INCLUDED

#include "Bitstream.h"

/*@
  requires valid_stream: \valid(stream);
  requires valid_array:  \valid(addr + (0..size-1));
  requires bit_size:     8 * size <= UINT32_MAX;
  requires valid_pos:    bitpos <= 8 * size;
  requires separated:    \separated(addr + (0..size-1), stream);

  assigns  stream->addr;
  assigns  stream->size;
  assigns  stream->bitpos;

  ensures  copy_addr:   stream->addr == addr;
  ensures  copy_size:   stream->size == size;
  ensures  copy_bitpos: stream->bitpos == bitpos;
  ensures  invariant:   Invariant(stream);
*/
void Bitstream_Init(Bitstream* stream, uint8_t* addr, uint32_t size, uint32_t bitpos);

#endif // BITSTREAM_INIT_H_INCLUDED

