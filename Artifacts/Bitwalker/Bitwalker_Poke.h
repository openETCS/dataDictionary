#ifndef Bitwalker_Poke_defined
#define Bitwalker_Poke_defined

#include "FramaCBits.h"

/*@
  requires array_length: \valid(addr + (0..size-1));
  requires bit_size:     8 * size <= UINT32_MAX;
  requires max_length:   length <= 64;
  requires max_pos:      start + length <= UINT32_MAX;

  assigns addr[0..size - 1];

  behavior  invalid_bit_sequence:
    assumes start + length  > 8 * size;
    assigns \nothing;
    ensures invalid_result:  \result == -1;

  behavior  value_too_big:
    assumes (start + length <= 8 * size)  &&  (1 << length) <= value && length < 64;
    assigns \nothing;
    ensures wrong_value_result:  \result == -2;

  behavior  normal_case:
    assumes (start + length <= 8 * size)  &&  (value < (1 << length) || length == 64);
    assigns addr[0..size - 1];

    //ensures unchanged_left:  BitsUnchanged{Old}(addr, 0, start);
    ensures unchanged_left:   \forall integer i; 0 <= i < start ==>
             (LeftBit8Array(addr, i) <==> \old(LeftBit8Array(addr, i)));

    ensures copied:          \forall integer i; start <= i < start + length ==>
             (LeftBit8Array(addr, i) <==> LeftBit64(value, 64 - length + i - start));

    ensures unchanged_right: \forall integer i; start + length <= i < 8 * size ==>
             (LeftBit8Array(addr, i) <==> \old(LeftBit8Array(addr, i)));

    ensures valid_result: \result == 0;

  complete behaviors;
  disjoint behaviors;
*/
int Bitwalker_Poke(uint8_t* addr, uint32_t size, uint32_t start, uint32_t length, uint64_t value);

#endif
