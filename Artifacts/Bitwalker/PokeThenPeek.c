
#include "PokeThenPeek.h"
#include "Bitwalker_Peek.h"
#include "Bitwalker_Poke.h"

uint64_t PokeThenPeek(uint32_t  start,
                      uint32_t  length,
                      uint8_t*  addr,
                      uint32_t  size,
                      uint64_t  value)
{
  //@ assert \forall integer i; 0 <= i < 64-length ==> !LeftBit64(value, i);
  int      poke_result = 0;
  uint64_t peek_result = 0u;

  poke_result =  Bitwalker_Poke(start, length, addr, size, value);
  //@ assert  poke_result == 0;

  peek_result = Bitwalker_Peek(start, length, addr, size);

  /*@ assert \forall integer i; 64-length <= i < 64 ==>
             (LeftBit64(peek_result, i) <==> LeftBit64(value, i)); */

  /*@ assert  \forall integer i; 0 <= i < 64 ==>
             (LeftBit64(peek_result, i) <==> LeftBit64(value, i)); */

  return peek_result;
}

