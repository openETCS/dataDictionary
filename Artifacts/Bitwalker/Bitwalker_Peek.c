#include "Bitwalker_Peek.h"
#include "Bit8Array.h"
#include "Bit64.h"

uint64_t Bitwalker_Peek(uint32_t  start, uint32_t  length, uint8_t*  addr, uint32_t  size)
{
  if ((start + length) > 8 * size)
  {
    return 0;
  }

  uint64_t retval = 0;

  /*@
    loop invariant 0 <= i <= length;

    loop invariant \forall integer k; 0 <= k < i ==>
                    (LeftBit8Array(addr, start+k) <==> LeftBit64(retval, 64-length+k));

    loop invariant \forall integer k; k < 64-length ==> !LeftBit64(retval, k);

    loop assigns i, retval;
    loop variant length - i;
  */
  for (uint32_t i = 0; i < length; i++)
  {
    //@ assert start + i < 8 * size;
    int flag = PeekBit8Array(addr, size, start + i);
    retval = PokeBit64(retval, 64u - length + i, flag);
  }

  return retval;
}


