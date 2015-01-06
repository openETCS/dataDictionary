
#include "PokeThenPeek.h"
#include "Bitwalker_Peek.h"
#include "Bitwalker_Poke.h"

uint64_t PokeThenPeek(uint8_t* addr, uint32_t size, uint32_t bitpos, uint32_t length, uint64_t value)
{
    Bitwalker_Poke(addr, size, bitpos, length, value);

    uint64_t peek_result = Bitwalker_Peek(addr, size, bitpos, length);

    //@ assert partial_copy: EqualBitRange(peek_result, value, 0, length);
    //@ assert full_copy:    EqualBitRange(peek_result, value, 0, 64);

    return peek_result;
}

