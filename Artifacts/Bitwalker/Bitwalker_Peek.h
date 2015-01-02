
#ifndef BITWALKER_PEEK_H_INCLUDED
#define BITWALKER_PEEK_H_INCLUDED

#include "Bitwalker.h"

/*@
  requires  array_length: \valid_read(addr + (0..size-1));
  requires  max_length:   length <= 64;
  requires  bit_size:     8 * size <= UINT32_MAX;
  requires  max_pos:      bitpos + length <= UINT32_MAX;

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

