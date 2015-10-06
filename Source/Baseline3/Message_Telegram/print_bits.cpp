
#include "print_bits.h"
#include "Bit8.h"

void print(const Bitstream& stream, uint32_t from, uint32_t to)
{
    for (uint32_t i = from; i != to; ++i)
    {
        if (((i - from) % 4) == 0)
        {
            std::cout << ' ';
        }

        std::cout << TestBit8Array(stream.addr, stream.size, i);
    }
}

