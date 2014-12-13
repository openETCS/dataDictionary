#include "Bitwalker_Peek.h"
#include "Bit8Array.h"
#include "Bit64.h"

uint64_t Bitwalker_Peek(uint8_t*  addr, uint32_t  size, uint32_t  start, uint32_t  length)
{
  if ((start + length) > 8 * size)
  {
    return 0;
  }

  uint64_t retval = 0;

  /*@
    loop invariant index:  0 <= i <= length;

    loop invariant copied: \forall integer k; start <= k < start + i ==>
                    (LeftBit8Array(addr, k) <==> LeftBit64(retval, 64 - length + k - start));

    loop invariant not_set: UpperBitsNotSet64(retval, length);

    loop assigns i, retval;
    loop variant length - i;
  */
  for (uint32_t i = 0; i < length; i++)
  {
    int flag = PeekBit8Array(addr, size, start + i);
    retval = PokeBit64(retval, 64u - length + i, flag);
  }

  return retval;
}


