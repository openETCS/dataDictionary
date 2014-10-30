
#include "PeekNext.h"
#include "Peek.h"

uint64_t Bitwalker_Peek_Next(Bitwalker* bw, uint32_t Length)
{
  // plausibility check is done when reading the bits
  uint64_t retval = Bitwalker_Peek(bw->Bitposition, Length, bw->Bitstream, bw->Size);

  bw->Bitposition += Length;
  return retval;
}

