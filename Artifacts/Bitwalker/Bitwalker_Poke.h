#ifndef Bitwalker_Poke_defined
#define Bitwalker_Poke_defined

#include "BitsFramaC.h"

/*@
  requires writeable_bitstream: \valid(addr + (0..size-1));
  requires valid_length: length < 64;
  requires no_overflow_1: start + length <= UINT32_MAX;
  requires no_overflow_2: 8 * size <= UINT_MAX;

  assigns addr[0..size - 1];

  behavior  invalid_bit_sequence:
    assumes start + length  > 8 * size;
    assigns \nothing;
    ensures \result == -1;

  behavior  value_too_big:
    assumes (start + length <= 8 * size)  &&  (1 << length) <= value;
    assigns \nothing;
    ensures \result == -2;

  behavior  normal_case:
    assumes (start + length <= 8 * size)  &&  value < (1 << length);
    assigns addr[0..size - 1];

    ensures \forall integer i; 0 <= i < start ==>
             (LeftBit8Array(addr, i) <==> \old(LeftBit8Array(addr, i)));

    ensures \forall integer i; start <= i < start + length ==>
             (LeftBit8Array(addr, i) <==> LeftBit64(value, 64 - length + i - start));

    ensures \forall integer i; start + length <= i < 8 * size ==>
             (LeftBit8Array(addr, i) <==> \old(LeftBit8Array(addr, i)));

    ensures \result == 0;

  complete behaviors;
  disjoint behaviors;
*/
int Bitwalker_Poke(uint32_t start, uint32_t length, uint8_t* addr, uint32_t size, uint64_t value);

#endif
