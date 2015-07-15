
#include "print_bits.h"

int main()
{
    uint8_t x = 73;

    print_bits(x);
    std::cout << std::endl;

    uint16_t y = 255 + x;

    print_bits(y);
    std::cout << std::endl;
}

