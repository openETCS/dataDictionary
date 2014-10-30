
#include "PokeNext.h"
#include "Poke.h"

int Bitwalker_Poke_Next(Bitwalker* bw, uint32_t Length, uint64_t Value)
{
  // plausibility check is done when reading the bits
  int retval = Bitwalker_Poke(bw->Bitposition, Length, bw->Bitstream, bw->Size, Value);

  //@ assert bw->Bitposition == \at(bw->Bitposition, Pre);
  bw->Bitposition += Length;

  return retval;
}

