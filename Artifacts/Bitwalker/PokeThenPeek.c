
#include "PokeThenPeek.h"
#include "Bitwalker_Peek.h"
#include "Bitwalker_Poke.h"

uint64_t PokeThenPeek(uint8_t* addr, uint32_t size, uint32_t start, uint32_t length, uint64_t value)
{
    int poke_result =  Bitwalker_Poke(addr, size, start, length, value);
    //@ assert result_zero:  poke_result == 0;

    uint64_t peek_result = Bitwalker_Peek(addr, size, start, length);

    /*@ assert partial_copy: \forall integer i; 64-length <= i < 64 ==>
               (LeftBit64(peek_result, i) <==> LeftBit64(value, i)); */

    /*@ assert full_copy:  \forall integer i; 0 <= i < 64 ==>
               (LeftBit64(peek_result, i) <==> LeftBit64(value, i)); */

    /*@ assert full_copy2:  \forall integer i; 0 <= i < 64 ==>
               (BitTest(peek_result, i) <==> BitTest(value, i)); */

    return peek_result;
}

