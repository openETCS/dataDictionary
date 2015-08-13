
#ifndef BIT8_H_INCLUDED
#define BIT8_H_INCLUDED

#include "FramaCBits.h"

/*@
    requires pre:  pos < 8;

    assigns \nothing;

    ensures pos:  \result != 0 <==> LeftBit8(value, pos);
*/
static inline int PeekBit8(uint8_t value, uint32_t pos)
{
    uint8_t mask = ((uint8_t) 1) << (7u - pos);
    uint8_t flag = value & mask;

    return flag != 0;
}


/*@
    requires pre: pos < 8;

    assigns \nothing;

    ensures left:   LeftEqualBitRange8(\result, value, 0,  pos);
    ensures pos:    LeftBit8(\result, pos) <==> (flag != 0);
    ensures right:  LeftEqualBitRange8(\result, value, pos + 1,  8);
*/
static inline uint8_t PokeBit8(uint8_t value, uint32_t pos, int flag)
{
    uint8_t mask = ((uint8_t) 1) << (7u - pos);

    return (flag == 0) ? (value & ~mask) : (value | mask);
}



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

    ensures left:   Unchanged{Here,Old}(addr, 0, pos);
    ensures middle: LeftBit8Array(addr, pos) <==> (flag != 0);
    ensures right:  Unchanged{Here,Old}(addr, pos + 1, 8 * size);
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


#endif // BIT8_H_INCLUDED

