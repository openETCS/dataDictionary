#include "Bitwalker_Peek.h"
#include "Bit8Array.h"
#include "Bit64.h"

uint64_t Bitwalker_Peek_Core(uint8_t* addr, uint32_t size, uint32_t start, uint32_t length)
{
    uint64_t value = 0;
    //@ assert start + length <= 8 * size;

    /*@
      loop invariant index:  0 <= i <= length;

      loop invariant copied: EqualBits64(addr, start, start + i, value, length);

      loop invariant not_set: UpperBitsNotSet(value, length);

      loop assigns i, value;
      loop variant length - i;
    */
    for (uint32_t i = 0; i < length; i++)
    {
        int flag = PeekBit8Array(addr, size, start + i);
        value = PokeBit64(value, 64u - length + i, flag);
    }

    return value;
}


uint64_t Bitwalker_Peek(uint8_t* addr, uint32_t size, uint32_t start, uint32_t length)
{
    if ((start + length) > 8 * size)
    {
        return 0;
    }
    else
    {
       return Bitwalker_Peek_Core(addr, size, start, length);
    }
}

