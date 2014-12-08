
#ifndef PeekThenPoke_defined
#define PeekThenPoke_defined

#include "FramaCBits.h"

/*@
    requires \valid(addr + (0..size-1));
    requires 8 * size <= UINT32_MAX;
    requires length <= 64;
    requires start + length <= 8 * size;

    assigns addr[0..size-1];

    ensures \result == 0;

    ensures \forall integer i; 0 <= i < 8 * size ==>
         (LeftBit8Array(addr, i) <==> \old(LeftBit8Array(addr, i)));
*/
int PeekThenPoke(uint8_t* addr, uint32_t size, uint32_t start, uint32_t length);

#endif

