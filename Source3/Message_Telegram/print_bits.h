
#ifndef PRINT_BITS_H_INCLUDED
#define PRINT_BITS_H_INCLUDED

#include <cstdint>
#include <iostream>
#include "Bitstream.h"

extern void print(const Bitstream& stream, uint32_t from, uint32_t to);

template<typename UnsignedType>
inline bool left_bit(UnsignedType value, uint32_t pos)
{
    const auto max_bit = (8 * sizeof(value)) - 1;
    UnsignedType mask = ((UnsignedType) 1) << (max_bit - pos);
    UnsignedType flag = value & mask;

    return flag != 0;
}


template<typename UnsignedType>
inline void print_bits(UnsignedType value)
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

#endif /* PRINT_BITS_H_INCLUDED */

