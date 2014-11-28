
#ifndef Bit8Array_defined
#define Bit8Array_defined

#include "BitsFramaC.h"

/*@
    requires \valid_read(addr + (0..size-1));
    requires left < 8 * size;
    requires 8 * size < UINT32_MAX;

    assigns \nothing;

    ensures (\result != 0) <==> LeftBit8Array(addr, left);
*/
int PeekBit8Array(uint8_t*  addr, uint32_t  size, uint32_t  left);



/*@
    requires 8 * size < UINT32_MAX;
    requires \valid(addr+(0..size-1));
    requires left < 8 * size;

    assigns addr[0..size-1];

    ensures \forall integer i; 0 <= i < size  &&  i != left/8 ==>
                 addr[i] == \old(addr[i]);

    ensures \forall integer i; 0 <= i < 8 * size  &&  i != left ==>
                ((LeftBit8Array(addr, i) <==> \old(LeftBit8Array(addr, i))));

    ensures LeftBit8Array(addr, left) <==> (flag != 0);
*/
void PokeBit8Array(uint8_t* addr, uint32_t size, uint32_t left, int flag);

#endif

