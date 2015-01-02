
#ifndef POKETHENPEEK_H_INCLUDED
#define POKETHENPEEK_H_INCLUDED

#include "Bitwalker.h"

/*@
    requires array_length:  \valid(addr + (0..size-1));
    requires bit_size:      8 * size <= UINT32_MAX;
    requires max_length:    length <= 64;
    requires max_pos:       NormalBitwalker(size, bitpos, length);
    requires max_value:     UpperBitsNotSet(value, length);

    assigns addr[0..size-1];

    ensures result_value:  \result == value;
*/
uint64_t PokeThenPeek(uint8_t* addr, uint32_t size, uint32_t bitpos, uint32_t length, uint64_t value);

#endif // POKETHENPEEK_H_INCLUDED

