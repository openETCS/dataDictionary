
#include "UpperBitsNotSet.h"


int UpperBitsNotSet64(uint64_t value, uint32_t length)
{
    if (length == 64)
    {
        return 1;
    }
    else
    {
        const uint64_t MaxValue = ((uint64_t) 1) << length;

        return (value >= MaxValue) ? 0 : 1;
    }
}

