
#include "PeekThenPoke.h"

int PeekThenPoke(unsigned int Start,
                 unsigned int Length,
                 uint8_t*     Bitstream,
                 unsigned int BitstreamSize)
{
  int result = 0;
  uint64_t value = Bitwalker_Peek(Start, Length, Bitstream, BitstreamSize);

  //@ assert value < (1 << Length);

  result =  Bitwalker_Poke(Start, Length, Bitstream, BitstreamSize, value);

  /*@ assert \forall integer i; Start <= i < Start + Length ==>
         (LeftBitInStream(Bitstream, i) <==> \at(LeftBitInStream(Bitstream, i), Pre)); */

  return result;
}
