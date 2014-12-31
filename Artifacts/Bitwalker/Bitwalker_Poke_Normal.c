#include "Bitwalker_Poke_Normal.h"
#include "Bit8Array.h"
#include "Bit64.h"

void Bitwalker_Poke_Normal(uint8_t* addr, uint32_t size, uint32_t start, uint32_t length, uint64_t value)
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

