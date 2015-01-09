#include "Bitwalker_Poke_Normal.h"
#include "Bit8Array.h"
#include "Bit64.h"

void Bitwalker_Poke_Normal(uint8_t* addr, uint32_t size, uint32_t bitpos, uint32_t length, uint64_t value)
{
    /*@
      loop invariant index:  bitpos <= i <= bitpos + length;

      loop invariant left:   EqualBits{Here,Pre}(addr, 0, bitpos);

      loop invariant middle: EqualBits(addr, bitpos, i, value, length);

      loop invariant right:  EqualBits{Here,Pre}(addr, i, 8 * size);

      loop assigns i, addr[0..size-1];

      loop variant bitpos + length - i;
    */
    for (uint32_t i = bitpos; i < bitpos + length; ++i)
    {
        int flag = PeekBit64(value, (64 - length) + (i - bitpos));
        PokeBit8Array(addr, size, i, flag);
    }
}

