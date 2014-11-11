
#include "PokeNext.h"
#include "Poke.h"

int Bitstream_Poke(Bitstream* stream, uint32_t length, uint64_t value)
{
  // plausibility check is done when reading the bits
  int retval = Bitwalker_Poke(stream->bitposition, length, stream->addr, stream->size, value);

  //@ assert stream->bitposition == \at(stream->bitposition, Pre);
  stream->bitposition += length;

  return retval;
}

