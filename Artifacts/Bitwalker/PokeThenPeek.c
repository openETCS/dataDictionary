
#include "PokeThenPeek.h"
#include "Bitwalker_Peek.h"
#include "Bitwalker_Poke.h"

uint64_t PokeThenPeek(uint8_t* addr, uint32_t size, uint32_t start, uint32_t length, uint64_t value)
{
    Bitwalker_Poke(addr, size, start, length, value);

    uint64_t peek_result = Bitwalker_Peek(addr, size, start, length);

    /*@ assert partial_copy: \forall integer i; 0 <= i < length ==>
               (BitTest(peek_result, i) <==> BitTest(value, i)); */

    /*@ assert full_copy:  \forall integer i; 0 <= i < 64 ==>
               (BitTest(peek_result, i) <==> BitTest(value, i)); */

    return peek_result;
}

