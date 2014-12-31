#include "Bitwalker_Peek.h"
#include "Bitwalker_Peek_Normal.h"
#include "Bit64.h"

uint64_t Bitwalker_Peek(uint8_t* addr, uint32_t size, uint32_t start, uint32_t length)
{
    if ((start + length) <= 8 * size)
    {
        return Bitwalker_Peek_Normal(addr, size, start, length);
    }
    else
    {
        return 0u;
    }
}

