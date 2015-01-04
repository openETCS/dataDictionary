
#include "Bit8.h"

int PeekBit8(uint8_t value, uint32_t pos)
{
    uint8_t mask = ((uint8_t) 1) << (7u - pos);
    uint8_t flag = value & mask;

    return flag != 0;
}


uint8_t PokeBit8(uint8_t value, uint32_t pos, int flag)
{
    uint8_t mask = ((uint8_t) 1) << (7u - pos);

    //@ assert helper: \forall uint8_t a, b; 0 <= (a & ~b) < 256;
    return (flag == 0) ? (value & ~mask) : (value | mask);
}

