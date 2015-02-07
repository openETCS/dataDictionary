#include "Bitwalker_Peek_Normal.h"
#include "Bit8Array.h"
#include "Bit64.h"

uint64_t Bitwalker_Peek_Normal(uint8_t* addr, uint32_t size, uint32_t bitpos, uint32_t length)
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
        int flag = PeekBit8Array(addr, size, i);
        value = PokeBit64(value, (64u - length) + (i - bitpos), flag);
    }

    return value;
}

