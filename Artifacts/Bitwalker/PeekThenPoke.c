
#include "PeekThenPoke.h"
#include "Bitwalker_Peek.h"
#include "Bitwalker_Poke.h"

int PeekThenPoke(uint32_t  start, uint32_t  length, uint8_t*  addr, uint32_t  size)
{
  int result = 0;
  uint64_t value = Bitwalker_Peek(start, length, addr, size);

  result =  Bitwalker_Poke(start, length, addr, size, value);

  /*@ assert \forall integer i; start <= i < start + length ==>
         (LeftBitInStream(addr, i) <==> \at(LeftBitInStream(addr, i), Pre)); */

  return result;
}
