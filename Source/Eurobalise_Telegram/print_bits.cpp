
#include <cstdint>
#include <iostream>

template<typename UnsignedType>
bool left_bit(UnsignedType value, uint32_t pos)
{
    const auto max_bit = (8 * sizeof(value)) - 1;
    UnsignedType mask = ((UnsignedType) 1) << (max_bit - pos);
    UnsignedType flag = value & mask;

    return flag != 0;
}


template<typename UnsignedType>
void print_bits(UnsignedType value)
{
    const auto number_bits = 8 * sizeof(value);

    for (uint32_t i = 0; i < number_bits; ++i)
    {
        if ((i % 4) == 0)
        {
            std::cout << ' ';
        }

        std::cout << left_bit(value, i);
    }
}


int main()
{
    uint8_t x = 73;

    print_bits(x);
    std::cout << std::endl;

    uint16_t y = 255 + x;

    print_bits(y);
    std::cout << std::endl;
}

