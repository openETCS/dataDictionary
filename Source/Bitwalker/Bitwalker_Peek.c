#include "Bitwalker_Peek.h"
#include "Bitwalker_Peek_Normal.h"
#include "Bit64.h"

uint64_t Bitwalker_Peek(uint8_t* addr, uint32_t size, uint32_t bitpos, uint32_t length)
{
    if (NormalBitwalker(size, bitpos, length))
    {
        return Bitwalker_Peek_Normal(addr, size, bitpos, length);
    }
    else
    {
        return 0u;
    }
}

