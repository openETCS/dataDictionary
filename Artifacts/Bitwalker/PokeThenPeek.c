
#include "PokeThenPeek.h"
#include "Peek.h"
#include "Poke.h"

uint64_t PokeThenPeek(uint32_t  Start,
                      uint32_t  Length,
                      uint8_t*  Bitstream,
                      uint32_t  BitstreamSize,
                      uint64_t  Value)
{
  //@ assert \forall integer i; 0 <= i < 64-Length ==> !LeftBit64(Value, i);
  int      poke_result = 0;
  uint64_t peek_result = 0u;

  poke_result =  Bitwalker_Poke(Start, Length, Bitstream, BitstreamSize, Value);
  //@ assert  poke_result == 0;

  peek_result = Bitwalker_Peek(Start, Length, Bitstream, BitstreamSize);

  /*@ assert \forall integer i; 64-Length <= i < 64 ==>
             (LeftBit64(peek_result, i) <==> LeftBit64(Value, i)); */

  /*@ assert  \forall integer i; 0 <= i < 64 ==>
             (LeftBit64(peek_result, i) <==> LeftBit64(Value, i)); */

  return peek_result;
}

