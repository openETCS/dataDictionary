
#ifndef Bit8Array_defined
#define Bit8Array_defined

#include "BitsFramaC.h"

/*@
    requires \valid_read(addr + (0..size-1));
    requires left < 8 * size;
    requires 8 * size < UINT_MAX;

    assigns \nothing;

    ensures (\result != 0) <==> LeftBitInStream(addr, left);
*/
int PeekBit8Array(uint8_t*  addr, uint32_t  size, uint32_t  left);



/*@
    requires 8 * size < UINT_MAX;
    requires \valid(addr+(0..size-1));
    requires left < 8 * size;

    assigns addr[0..size-1];

    ensures \forall integer i; 0 <= i < left/8 ==> addr[i] == \old(addr[i]);

    ensures \forall integer i; left/8 < i < size ==> addr[i] == \old(addr[i]);

    ensures \forall integer i; 0 <= i < left ==>
                ((LeftBitInStream(addr, i) <==> \old(LeftBitInStream(addr, i))));

    ensures LeftBitInStream(addr, left) <==> (flag != 0);

    ensures \forall integer i; left < i < 8 * size ==>
                ((LeftBitInStream(addr, i) <==> \old(LeftBitInStream(addr, i))));
*/
void PokeBit8Array(uint8_t* addr, uint32_t size, uint32_t left, int flag);

#endif

