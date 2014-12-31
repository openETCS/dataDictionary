#include "Bitwalker_Poke.h"
#include "Bitwalker_Poke_Normal.h"
#include "Bit64.h"


int Bitwalker_Poke(uint8_t*  addr, uint32_t  size, uint32_t  start, uint32_t  length, uint64_t  value)
{
    if ((start + length)  <= 8 * size)
    {
        if (UpperBitsNotSet64(value, length))
        {
            Bitwalker_Poke_Normal(addr, size, start, length, value);

            return 0;
        }
        else
        {
            return -2;
        }
    }
    else
    {
        return -1;
    }
}

