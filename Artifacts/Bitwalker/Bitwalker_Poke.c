#include "Bitwalker_Poke.h"
#include "Bit8Array.h"
#include "Bit64.h"

void Bitwalker_Poke_Core(uint8_t* addr, uint32_t size, uint32_t start, uint32_t length, uint64_t value)
{
    /*@
      loop invariant index:  0 <= i <= length;

      loop invariant left:   BitsUnchanged{Here,Pre}(addr, 0, start);

      loop invariant middle: EqualBits64(addr, start, start + i, value, length);

      loop invariant right:  BitsUnchanged{Here,Pre}(addr, start + i, 8 * size);

      loop assigns i, addr[0..size-1];

      loop variant length - i;
    */
    for (uint32_t i = 0; i < length; ++i)
    {
        int flag = PeekBit64(value, (64 - length) + i);
        PokeBit8Array(addr, size, start + i, flag);
    }
}


int Bitwalker_Poke(uint8_t*  addr, uint32_t  size, uint32_t  start, uint32_t  length, uint64_t  value)
{
    if ((start + length)  > 8 * size)
    {
        return -1;	// error: invalid_bit_sequence
    }

    if (UpperBitsNotSet64(value, length))
    {
        Bitwalker_Poke_Core(addr, size, start, length, value);

        return 0;
    }
    else
    {
        return -2;
    }
}

