#include "Bitwalker_Poke.h"
#include "Bitwalker_Poke_Normal.h"
#include "UpperBitsNotSet.h"


int Bitwalker_Poke(uint8_t*  addr, uint32_t  size, uint32_t  bitpos, uint32_t  length, uint64_t  value)
{
    if (NormalBitwalker(size, bitpos, length))
    {
        if (UpperBitsNotSet64(value, length))
        {
            Bitwalker_Poke_Normal(addr, size, bitpos, length, value);

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

