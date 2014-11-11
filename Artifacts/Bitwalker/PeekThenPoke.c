
#include "PeekThenPoke.h"
#include "Bitwalker_Peek.h"
#include "Bitwalker_Poke.h"

int PeekThenPoke(uint32_t  Start,
                 uint32_t  Length,
                 uint8_t*  Bitstream,
                 uint32_t  BitstreamSize)
{
  int result = 0;
  uint64_t value = Bitwalker_Peek(Start, Length, Bitstream, BitstreamSize);

  result =  Bitwalker_Poke(Start, Length, Bitstream, BitstreamSize, value);

  /*@ assert \forall integer i; Start <= i < Start + Length ==>
         (LeftBitInStream(Bitstream, i) <==> \at(LeftBitInStream(Bitstream, i), Pre)); */

  return result;
}
