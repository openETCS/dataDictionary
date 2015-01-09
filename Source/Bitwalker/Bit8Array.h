
#ifndef BIT8ARRAY_H_defined
#define BIT8ARRAY_H_defined

#include "Bit8.h"

/*@
    requires valid:  \valid_read(addr + (0..size-1));
    requires size:   8 * size <= UINT32_MAX;
    requires pos:    pos < 8 * size;

    assigns \nothing;

    ensures result:  \result != 0 <==> LeftBit8Array(addr, pos);
*/
static inline int PeekBit8Array(uint8_t*  addr, uint32_t size, uint32_t pos)
{
    return PeekBit8(addr[pos / 8], pos % 8);
}


/*@
    requires valid:  \valid(addr + (0..size-1));
    requires size:   8 * size <= UINT32_MAX;
    requires pos:    pos < 8 * size;

    assigns addr[0..size-1];

    ensures left:   EqualBits{Here,Old}(addr, 0, pos);
    ensures middle: LeftBit8Array(addr, pos) <==> (flag != 0);
    ensures right:  EqualBits{Here,Old}(addr, pos + 1, 8 * size);
*/
static inline void PokeBit8Array(uint8_t* addr, uint32_t size, uint32_t pos, int flag)
{
    uint32_t i = pos / 8u;
    uint32_t k = pos % 8u;

    addr[i] = PokeBit8(addr[i], k, flag);

    // The following assertion claims that in byte with index "pos/8"
    // the bits with indices different from "k" do not change
    /*@
      assert bits_in_byte:
        \forall integer j; (0 <= j < 8  && j != k) ==>
        (LeftBit8(addr[pos/8], j) <==> \at(LeftBit8(addr[pos/8], j), Pre));
    */

    // The following assertion claims that in every byte
    // with an index that is different from "pos/8" no bit is changed.

    /*@
        assert other_bytes:
        \forall integer l, j; (0 <= l < size  &&  l != pos/8  &&  0 <= j < 8) ==>
          (LeftBit8(addr[l], j) <==> \at(LeftBit8(addr[l], j), Pre));
    */

}




#endif // BIT8ARRAY_H_defined

