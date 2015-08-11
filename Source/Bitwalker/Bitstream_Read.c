
#include "Bitstream_Read.h"
#include "Bit8Array.h"
#include "Bit64.h"

uint64_t Bitstream_Read(Bitstream* s, uint32_t length)
{
    uint64_t value = 0;
    const uint32_t bitpos = s->bitpos;

    /*@
      loop invariant  bound:  bitpos <= i <= bitpos + length;
      loop invariant  equal:  EqualBits(s->addr, bitpos, i, value, length);
      loop invariant  upper:  UpperBitsNotSet(value, length);

      loop assigns i, value;
      loop variant bitpos + length - i;
    */
    for (uint32_t i = bitpos; i < bitpos + length; ++i)
    {
        int flag = PeekBit8Array(s->addr, s->size, i);
        value = PokeBit64(value, (64u - length) + (i - bitpos), flag);
    }

    s->bitpos += length;

    return value;
}

