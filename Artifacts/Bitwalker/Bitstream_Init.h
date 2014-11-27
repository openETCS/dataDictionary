#ifndef INIT_H
#define INIT_H

#include "Bitstream.h"
#include "BitstreamInvariant.h"

/*@
  requires \valid(stream);
  requires \valid(addr + (0..size-1));
  requires 8 * size <= UINT32_MAX;
  requires bitpos <= 8 * size;
  requires \separated(addr + (0..size-1), stream);

  assigns  stream->addr;
  assigns  stream->size;
  assigns  stream->bitpos;

  ensures  stream->addr == addr;
  ensures  stream->size == size;
  ensures  stream->bitpos == bitpos;
  ensures  BitstreamInvariant(stream);
*/
void Bitstream_Init(Bitstream* stream, uint8_t* addr, uint32_t size, uint32_t bitpos);

#endif

