
#include "Bitwalker.h"


int NormalBitwalker(uint32_t size, uint32_t bitpos, uint32_t length)
{
    return bitpos + length <= 8 * size;
}

