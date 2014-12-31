
#ifndef BIT8ARRAY_H_defined
#define BIT8ARRAY_H_defined

#include "FramaCBits.h"

/*@
    requires array_length:  \valid_read(addr + (0..size-1));
    requires bit_size:      8 * size < UINT32_MAX;
    requires bit_index:     pos < 8 * size;

    assigns \nothing;

    ensures set_bit:  \result != 0 <==> LeftBit8Array(addr, pos);
*/
int PeekBit8Array(uint8_t*  addr, uint32_t  size, uint32_t  pos);



/*@
    requires array_length:  \valid(addr + (0..size-1));
    requires bit_size:      8 * size < UINT32_MAX;
    requires bit_index:     pos < 8 * size;

    assigns addr[0..size-1];

    //ensures unchanged_bytes:
         //\forall integer i; 0 <= i < size  &&  i != pos/8 ==> addr[i] == \old(addr[i]);

    ensures unchanged_bits:
         \forall integer i; 0 <= i < 8 * size  &&  i != pos ==>
                ((LeftBit8Array(addr, i) <==> \old(LeftBit8Array(addr, i))));

    ensures set_bit:   LeftBit8Array(addr, pos) <==> (flag != 0);
*/
void PokeBit8Array(uint8_t* addr, uint32_t size, uint32_t pos, int flag);

#endif // BIT8ARRAY_H_defined

