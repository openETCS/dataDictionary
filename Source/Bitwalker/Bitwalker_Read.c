#include "Bitwalker_Read.h"
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
        //@ assert (i - bitpos) + (64u - length) == 64 - (bitpos + length) + i;
        //@ assert Bit8Array(addr, i) <==> BitTest(value, bitpos + length - i - 1);

    }

    return value;
}

