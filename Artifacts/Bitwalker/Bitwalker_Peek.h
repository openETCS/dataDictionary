
#ifndef BITWALKER_PEEK_H_INCLUDED
#define BITWALKER_PEEK_H_INCLUDED

#include "FramaCBits.h"

/*@
  requires  array_length: \valid_read(addr + (0..size-1));
  requires  max_length:   length <= 64;
  requires  bit_size:     8 * size <= UINT32_MAX;
  requires  max_pos:      start + length <= 8 * size;

  assigns \nothing;

  ensures copied:    EqualBits64(addr, start, start + length, \result);

  ensures not_set:   UpperBitsNotSet(\result, length);
*/
uint64_t Bitwalker_Peek_Core(uint8_t* addr, uint32_t size, uint32_t start, uint32_t length);

/*@
  requires  array_length: \valid_read(addr + (0..size-1));
  requires  max_length:   length <= 64;
  requires  bit_size:     8 * size <= UINT32_MAX;
  requires  max_pos:      start + length <= UINT32_MAX;

  assigns \nothing;

  behavior  invalid_bit_sequence:
    assumes start + length > 8 * size;

    assigns \nothing;

    ensures invalid_result: \result == 0;

  behavior  normal_case:
    assumes start + length <= 8 * size;

    assigns \nothing;

    ensures copied:  EqualBits64(addr, start, start + length, \result);

    ensures not_set: UpperBitsNotSet(\result, length);

  complete behaviors;
  disjoint behaviors;
*/
uint64_t Bitwalker_Peek(uint8_t* addr, uint32_t size, uint32_t start, uint32_t length);

#endif // BITWALKER_PEEK_H_INCLUDED

