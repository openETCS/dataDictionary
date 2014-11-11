#include "Bitwalker_Peek.h"
#include "Bit8Array.h"
#include "Bit64.h"

uint64_t Bitwalker_Peek(uint32_t  Start,
                        uint32_t  Length,
                        uint8_t*  Bitstream,
                        uint32_t  BitstreamSize)
{
  if ((Start + Length) > 8 * BitstreamSize)
  {
    return 0;
  }

  uint64_t retval = 0;

  /*@
    loop invariant 0 <= i <= Length;

    loop invariant \forall integer k; 0 <= k < i ==>
                    (LeftBitInStream(Bitstream, Start+k) <==> LeftBit64(retval, 64-Length+k));

    loop invariant \forall integer k; 0 <= k < 64-Length ==> !LeftBit64(retval, k);

    loop assigns i, retval;
    loop variant Length - i;
  */
  for (uint32_t i = 0; i < Length; i++)
  {
    //@ assert Start + i < 8 * BitstreamSize;
    int flag = PeekBit8Array(Bitstream, BitstreamSize, Start + i);
    retval = PokeBit64(retval, 64u - Length + i, flag);
  }

  return retval;
}


