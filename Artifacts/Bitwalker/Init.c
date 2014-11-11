#include "Init.h"

void
Bitstream_Init(Bitstream* stream, uint8_t* addr, uint32_t size, uint32_t bitposition)
{
  stream->addr         = addr;
  stream->size         = size;
  stream->bitposition  = bitposition;
}

