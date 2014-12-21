
#ifndef PEEKTHENPOKE_H_INCLUDED
#define PEEKTHENPOKE_H_INCLUDED

#include "FramaCBits.h"

/*@
    requires array_length: \valid(addr + (0..size-1));
    requires bit_size:     8 * size <= UINT32_MAX;
    requires max_length:   length <= 64;
    requires max_pos:      start + length <= 8 * size;

    assigns addr[0..size-1];

    ensures result_zero: \result == 0;

    ensures unchanged:  BitsUnchanged{Old}(addr, 0, 8*size);
*/
int PeekThenPoke(uint8_t* addr, uint32_t size, uint32_t start, uint32_t length);

#endif // PEEKTHENPOKE_H_INCLUDED

