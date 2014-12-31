
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

    ensures left:   BitsUnchanged{Here,Old}(addr, 0, pos);

    ensures middle: LeftBit8Array(addr, pos) <==> (flag != 0);

    ensures right:  BitsUnchanged{Here,Old}(addr, pos + 1, 8 * size);

*/
void PokeBit8Array(uint8_t* addr, uint32_t size, uint32_t pos, int flag);

#endif // BIT8ARRAY_H_defined

