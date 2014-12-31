
#include "PeekThenPoke.h"
#include "Bitwalker_Peek.h"
#include "Bitwalker_Poke.h"

int PeekThenPoke(uint8_t* addr, uint32_t size, uint32_t start, uint32_t length)
{
    uint64_t value = Bitwalker_Peek(addr, size, start, length);
    //@ assert copied:  EqualBits64(addr, start, start + length, value);

    int result =  Bitwalker_Poke(addr, size, start, length, value);
    //@ assert unchanged:  BitsUnchanged{Here,Pre}(addr, start, start + length);

    return result;
}
