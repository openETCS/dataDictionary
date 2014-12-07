
#ifndef Peek_defined
#define Peek_defined

#include "FramaCBits.h"

/*@
  requires \valid_read(addr + (0..size-1));
  requires length <= 64;
  requires start + length <= UINT32_MAX;
  requires 8 * size <= UINT_MAX;

  assigns \nothing;

  behavior  invalid_bit_sequence:
    assumes start + length > 8 * size;
    assigns \nothing;
    ensures \result == 0;

  behavior  normal_case:
    assumes start + length <= 8 * size;
    assigns \nothing;

    ensures \forall integer i; 0 <= i < length ==>
              (LeftBit8Array(addr, start+i) <==> LeftBit64(\result, 64-length + i));

    ensures \forall integer i; 0 <= i < 64-length ==> !LeftBit64(\result, i);

    ensures \result < (1 << length);

  complete behaviors;
  disjoint behaviors;
*/
uint64_t Bitwalker_Peek(uint8_t* addr, uint32_t size, uint32_t start, uint32_t length);

#endif
