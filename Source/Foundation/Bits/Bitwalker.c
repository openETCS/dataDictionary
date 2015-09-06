
#include "Bitwalker.h"
#include "Bit8.h"
#include "Bit64.h"

uint64_t Bitwalker_Read(uint8_t* addr, uint32_t size, uint32_t bitpos, uint32_t length)
{
    uint64_t value = 0;

    /*@
      loop invariant  bound:  bitpos <= i <= bitpos + length;
      loop invariant  equal:  EqualBits(addr, bitpos, i, value, length);
      loop invariant  upper:  UpperBitsNotSet(value, length);

      loop assigns i, value;
      loop variant bitpos + length - i;
    */
    for (uint32_t i = bitpos; i < bitpos + length; ++i)
    {
        int flag = TestBit8Array(addr, size, i);
        value = SetBit64(value, (i - bitpos) + (64u - length), flag);
    }

    return value;
}

void Bitwalker_Write(uint8_t* addr, uint32_t size, uint32_t bitpos, uint32_t length, uint64_t value)
{
    /*@
      loop invariant bound:   bitpos <= i <= bitpos + length;
      loop invariant left:    Unchanged{Here,Pre}(addr, 0, bitpos);
      loop invariant middle:  EqualBits(addr, bitpos, i, value, length);
      loop invariant right:   Unchanged{Here,Pre}(addr, i, 8 * size);

      loop assigns  i, addr[0..size-1];
      loop variant  bitpos + length - i;
    */
    for (uint32_t i = bitpos; i < bitpos + length; ++i)
    {
        int flag = TestBit64(value, (64 - length) + (i - bitpos));
        SetBit8Array(addr, size, i, flag);
    }
}

