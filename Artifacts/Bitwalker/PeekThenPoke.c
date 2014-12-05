
#include "PeekThenPoke.h"
#include "Bitwalker_Peek.h"
#include "Bitwalker_Poke.h"

int PeekThenPoke(uint32_t  start, uint32_t  length, uint8_t*  addr, uint32_t  size)
{
  int result = 0;
  uint64_t value = Bitwalker_Peek(start, length, addr, size);

  /*@ assert \forall integer i; start <= i < start + length ==>
         (LeftBit8Array(addr, i) <==> LeftBit64(value, 64 - (start + length) + i));
   */

  result =  Bitwalker_Poke(start, length, addr, size, value);

  /*@ assert \forall integer i; start <= i < start + length ==>
         (LeftBit8Array(addr, i) <==> \at(LeftBit8Array(addr, i), Pre));
   */

  return result;
}
