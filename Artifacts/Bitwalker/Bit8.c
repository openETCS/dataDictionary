
#include "Bit8.h"

int PeekBit8(uint8_t byte, uint32_t pos)
{
    uint8_t mask = ((uint8_t) 1) << (7u - pos);
    uint8_t flag = byte & mask;

    return flag != 0;
}


uint8_t PokeBit8(uint8_t byte, uint32_t pos, int flag)
{
    uint8_t mask = ((uint8_t) 1) << (7u - pos);

    return (flag == 0) ? (byte & ~mask) : (byte | mask);
}

