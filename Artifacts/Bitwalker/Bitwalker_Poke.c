#include "Bitwalker_Poke.h"
#include "Bit8Array.h"
#include "Bit64.h"

int Bitwalker_Poke(uint8_t*  addr, uint32_t  size, uint32_t  start, uint32_t  length, uint64_t  value)
{
  if ((start + length)  > 8 * size)
  {
    return -1;	// error: invalid_bit_sequence
  }

  if (length < 64)
  {
    // compute 2^length
    const uint64_t MaxValue = ((uint64_t) 1) << length;

    if (value >= MaxValue)
    {
      return -2;  // error: value_too_big
    }
  }

  /*@
    loop invariant index:  0 <= i <= length;
    //     loop invariant unchanged_left:  BitsUnchanged{Pre}(addr, 0, start);
    loop invariant unchanged_left:  \forall integer k; 0 <= k < start ==>
           (LeftBit8Array(addr, k) <==> \at(LeftBit8Array(addr, k), Pre));

    loop invariant copied:          \forall integer k; start <= k < start + i ==>
           (LeftBit8Array(addr, k) <==> LeftBit64(value, 64 - length + k - start));

    loop invariant unchanged_right: \forall integer k; start+i <= k < 8*size ==>
           (LeftBit8Array(addr, k) <==> \at(LeftBit8Array(addr, k), Pre));

    loop assigns i, addr[0..size-1];
    loop variant length - i;
  */
  for (uint32_t i = 0; i < length; ++i)
  {
    int flag = PeekBit64(value, (64 - length) + i);
    PokeBit8Array(addr, size, start + i, flag);
  }

  return 0;
}

