
#include "Bit64.h"

int PeekBit64(uint64_t value, uint32_t pos)
{
    uint64_t mask = ((uint64_t) 1) << (63u - pos);
    uint64_t flag = value & mask;

    return flag != 0u;
}


uint64_t PokeBit64(uint64_t value, uint32_t pos, int flag)
{
    uint64_t mask = ((uint64_t) 1u) << (63 - pos);

    return (flag == 0) ? (value & ~mask) : (value | mask);
}


int UpperBitsNotSet64(uint64_t value, uint32_t length)
{
    if (length < 64)
    {
        // compute 2^length
        const uint64_t MaxValue = ((uint64_t) 1) << length;

        return (value >= MaxValue) ? 0 : 1;
    }
    else
    {
        return 1;
    }
}



