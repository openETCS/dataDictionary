
#include "PeekThenPoke.h"
#include "Bitwalker_Peek.h"
#include "Bitwalker_Poke.h"

int PeekThenPoke(uint8_t* addr, uint32_t size, uint32_t bitpos, uint32_t length)
{
    uint64_t value = Bitwalker_Peek(addr, size, bitpos, length);
    //@ assert equal:  EqualBits(addr, bitpos, bitpos + length, value);

    int result =  Bitwalker_Poke(addr, size, bitpos, length, value);
    //@ assert unchanged:  EqualBits{Here,Pre}(addr, bitpos, bitpos + length);

    return result;
}
