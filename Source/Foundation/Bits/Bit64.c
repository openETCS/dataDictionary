
#include "Bit64.h"

int UpperBitsNotSet64(uint64_t value, uint32_t length)
{
    if (length == 64)
    {
        return 1;
    }
    else
    {
        const uint64_t MaxValue = ((uint64_t) 1) << length;
        // assert equiv: UpperBitsNotSet(value, length) <==> value < MaxValue;

        return value < MaxValue;
    }
}

