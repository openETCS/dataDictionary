
#ifndef BITWALKER_POKE_H_INCLUDED
#define BITWALKER_POKE_H_INCLUDED

#include "Bitwalker.h"

/*@
  requires valid:      Writeable(addr, size);
  requires invariant:  BitwalkerInvariant(size, bitpos, length);

  assigns addr[0..size - 1];

  behavior  normal_case:
    assumes NormalBitwalker{Pre}(size, bitpos, length)  &&  UpperBitsNotSet{Pre}(value, length);

    assigns addr[0..size - 1];

    ensures  left:    Unchanged{Here,Old}(addr, 0, bitpos);
    ensures  middle:  EqualBits(addr, bitpos, bitpos + length, value);
    ensures  right:   Unchanged{Here,Old}(addr, bitpos + length, 8 * size);
    ensures  result:  \result == 0;

  behavior  value_too_big:
    assumes NormalBitwalker{Pre}(size, bitpos, length)  &&  !UpperBitsNotSet{Pre}(value, length);

    assigns \nothing;

    ensures result:  \result == -2;

  behavior  invalid_bit_sequence:
    assumes !NormalBitwalker{Pre}(size, bitpos, length);

    assigns \nothing;

    ensures result:  \result == -1;

  complete behaviors;
  disjoint behaviors;
*/
int Bitwalker_Poke(uint8_t* addr, uint32_t size, uint32_t bitpos, uint32_t length, uint64_t value);

#endif // BITWALKER_POKE_H_INCLUDED

