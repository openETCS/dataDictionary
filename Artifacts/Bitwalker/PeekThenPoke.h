
#ifndef PeekThenPoke_defined
#define PeekThenPoke_defined

#include "BitsFramaC.h"

/*@
    requires \valid(addr + (0..size-1));
    requires 8 * size <= UINT32_MAX;
    requires 0 <= length < 64;
    requires start + length <= 8 * size;

    assigns addr[0..size-1];

    ensures \result == 0;

    ensures \forall integer i; 0 <= i < 8 * size ==>
         (LeftBitInStream(addr, i) <==> \old(LeftBitInStream(addr, i)));
*/
int PeekThenPoke(uint32_t start, uint32_t length, uint8_t* addr, uint32_t size);

#endif

