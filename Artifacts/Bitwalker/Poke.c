#include "Poke.h"
#include "Bit8Array.h"
#include "Bit64.h"

int Bitwalker_Poke(uint32_t  Start,
                   uint32_t  Length,
                   uint8_t*  Bitstream,
                   uint32_t  BitstreamSize,
                   uint64_t  Value)
{
  if ((Start + Length)  > 8 * BitstreamSize)
  {
    return -1;	// error: invalid_bit_sequence
  }

  // compute pow2(Length)
  const uint64_t MaxValue = ((uint64_t) 1) << Length;
  //@ assert MaxValue == 1 << Length;

  if (Value >= MaxValue)
  {
    return -2;  // error: value_too_big
  }

  /*@
    loop invariant 0 <= i <= Length;
    loop invariant \forall integer k; 0 <= k < Start ==>
                    (LeftBitInStream(Bitstream, k) <==> \at(LeftBitInStream(Bitstream, k), Pre));

    loop invariant \forall integer k; 0 <= k < i ==>
                    (LeftBitInStream(Bitstream, Start+k) <==> LeftBit64(Value, (64-Length)+k));

    loop invariant \forall integer k; Start+i <= k < 8*BitstreamSize ==>
                    (LeftBitInStream(Bitstream, k) <==> \at(LeftBitInStream(Bitstream, k), Pre));

    loop assigns i, Bitstream[0..BitstreamSize-1];
    loop variant Length - i;
  */
  for (uint32_t i = 0; i < Length; ++i)
  {
    int flag = PeekBit64(Value, (64 - Length) + i);
    PokeBit8Array(Bitstream, BitstreamSize, Start + i, flag);
  }

  return 0;
}

