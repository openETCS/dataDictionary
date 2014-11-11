
#include "Bitstream_Read.h"
#include "Bitwalker_Peek.h"

uint64_t Bitstream_Read(Bitstream* stream, uint32_t length)
{
  // plausibility check is done when reading the bits
  uint64_t retval = Bitwalker_Peek(stream->bitposition, length, stream->addr, stream->size);

  stream->bitposition += length;
  return retval;
}

