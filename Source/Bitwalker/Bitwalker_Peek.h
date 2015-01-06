
#ifndef BITWALKER_PEEK_H_INCLUDED
#define BITWALKER_PEEK_H_INCLUDED

#include "Bitwalker.h"

/*@
  requires valid:     Readable(addr, size);

  requires invariant: BitwalkerInvariant(size, bitpos, length);

  assigns \nothing;

  behavior  normal_case:
    assumes NormalBitwalker{Pre}(size, bitpos, length);

    assigns \nothing;

    ensures copied:  EqualBits64(addr, bitpos, bitpos + length, \result);

    ensures not_set: UpperBitsNotSet(\result, length);

  behavior  invalid_bit_sequence:
    assumes !NormalBitwalker{Pre}(size, bitpos, length);

    assigns \nothing;

    ensures invalid_result: \result == 0;

  complete behaviors;
  disjoint behaviors;
*/
uint64_t Bitwalker_Peek(uint8_t* addr, uint32_t size, uint32_t bitpos, uint32_t length);

#endif // BITWALKER_PEEK_H_INCLUDED

