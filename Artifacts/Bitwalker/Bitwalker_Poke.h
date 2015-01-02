
#ifndef BITWALKER_POKE_H_INCLUDED
#define BITWALKER_POKE_H_INCLUDED

#include "FramaCBits.h"

/*@
  requires array_length: \valid(addr + (0..size-1));
  requires bit_size:     8 * size <= UINT32_MAX;
  requires max_length:   length <= 64;
  requires max_pos:      bitpos + length <= UINT32_MAX;

  assigns addr[0..size - 1];

  behavior  invalid_bit_sequence:
    assumes bitpos + length  > 8 * size;
    assigns \nothing;
    ensures invalid_result:  \result == -1;

  behavior  value_too_big:
    assumes (bitpos + length <= 8 * size)  &&  !UpperBitsNotSet{Pre}(value, length);
    assigns \nothing;
    ensures wrong_value_result:  \result == -2;

  behavior  normal_case:
    assumes (bitpos + length <= 8 * size)  &&  UpperBitsNotSet{Pre}(value, length);
    assigns addr[0..size - 1];

    ensures left:   BitsUnchanged{Here,Old}(addr, 0, bitpos);

    ensures middle: EqualBits64(addr, bitpos, bitpos + length, value);

    ensures right:  BitsUnchanged{Here,Old}(addr, bitpos + length, 8 * size);

    ensures valid_result: \result == 0;

  complete behaviors;
  disjoint behaviors;
*/
int Bitwalker_Poke(uint8_t* addr, uint32_t size, uint32_t bitpos, uint32_t length, uint64_t value);

#endif // BITWALKER_POKE_H_INCLUDED

