
#ifndef PokeThenPeek_defined
#define PokeThenPeek_defined

#include "BitsFramaC.h"

/*@
    requires \valid(addr + (0..size-1));
    requires 8 * size <= UINT_MAX;
    requires 0 <= length < 64;
    requires start + length <= 8 * size;
    requires value < (1 << length);

    assigns addr[0..size-1];

    ensures \result == value;
*/
uint64_t PokeThenPeek(uint32_t  start,
                      uint32_t  length,
                      uint8_t*  addr,
                      uint32_t  size,
                      uint64_t  value);

#endif

