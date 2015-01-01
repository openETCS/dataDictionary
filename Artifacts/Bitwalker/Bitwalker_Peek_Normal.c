#include "Bitwalker_Peek_Normal.h"
#include "Bit8Array.h"
#include "Bit64.h"

uint64_t Bitwalker_Peek_Normal(uint8_t* addr, uint32_t size, uint32_t start, uint32_t length)
{
    uint64_t value = 0;

    /*@
      loop invariant index:  start <= i <= start + length;

      loop invariant copied: EqualBits64(addr, start, i, value, length);

      loop invariant not_set: UpperBitsNotSet(value, length);

      loop assigns i, value;

      loop variant start + length - i;
    */
    for (uint32_t i = start; i < start + length; ++i)
    {
        int flag = PeekBit8Array(addr, size, i);
        value = PokeBit64(value, (64u - length) + (i - start), flag);
    }

    return value;
}

