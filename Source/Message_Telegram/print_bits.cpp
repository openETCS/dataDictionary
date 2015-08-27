
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

/*
int main()
{
    uint8_t x = 73;

    print_bits(x);
    std::cout << std::endl;

    uint16_t y = 255 + x;

    print_bits(y);
    std::cout << std::endl;
}
*/
