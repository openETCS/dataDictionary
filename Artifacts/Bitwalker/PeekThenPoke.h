
#ifndef PeekThenPoke_defined
#define PeekThenPoke_defined

#include "FramaCBits.h"

/*@
    requires array_length: \valid(addr + (0..size-1));
    requires bit_size:     8 * size <= UINT32_MAX;
    requires max_length:   length <= 64;
    requires max_pos:      start + length <= 8 * size;

    assigns addr[0..size-1];

    ensures result_zero: \result == 0;

    ensures unchanged:  \forall integer i; 0 <= i < 8 * size ==>
         (LeftBit8Array(addr, i) <==> \old(LeftBit8Array(addr, i)));
*/
int PeekThenPoke(uint8_t* addr, uint32_t size, uint32_t start, uint32_t length);

#endif

