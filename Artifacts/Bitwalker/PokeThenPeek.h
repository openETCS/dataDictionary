
#ifndef PokeThenPeek_defined
#define PokeThenPeek_defined

#include "FramaCBits.h"

/*@
    requires array_length:  \valid(addr + (0..size-1));
    requires bit_size:      8 * size <= UINT32_MAX;
    requires max_length:    length <= 64;
    requires max_pos:       start + length <= 8 * size;
    requires max_value:     UpperBitsNotSet(value, length);

    assigns addr[0..size-1];

    ensures result_value:  \result == value;
*/
uint64_t PokeThenPeek(uint8_t* addr, uint32_t size,
                      uint32_t start, uint32_t length, uint64_t value);

#endif

