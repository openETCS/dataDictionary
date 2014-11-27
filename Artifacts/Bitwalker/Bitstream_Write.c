
#include "Bitstream_Write.h"
#include "Bitwalker_Poke.h"

int Bitstream_Write(Bitstream* stream, uint32_t length, uint64_t value)
{
  // plausibility check is done when reading the bits
  int retval = Bitwalker_Poke(stream->bitpos, length, stream->addr, stream->size, value);

  //@ assert stream->bitpos == \at(stream->bitpos, Pre);
  stream->bitpos += length;

  return retval;
}

