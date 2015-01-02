
#ifndef BITWALKER_POKE_NORMAL_H_INCLUDED
#define BITWALKER_POKE_NORMAL_H_INCLUDED

#include "Bitwalker.h"

/*@
  requires array_length: \valid(addr + (0..size-1));
  requires max_length:   length <= 64;
  requires bit_size:     8 * size <= UINT32_MAX;
  requires max_pos:      bitpos + length <= 8 * size;
  requires not_set:      UpperBitsNotSet(value, length);

  assigns addr[0..size - 1];

  ensures left:   BitsUnchanged{Here,Old}(addr, 0, bitpos);

  ensures middle: EqualBits64(addr, bitpos, bitpos + length, value);

  ensures right:  BitsUnchanged{Here,Old}(addr, bitpos + length, 8 * size);
*/
void Bitwalker_Poke_Normal(uint8_t* addr, uint32_t size, uint32_t bitpos, uint32_t length, uint64_t value);

#endif // BITWALKER_POKE_NORMAL_H_INCLUDED

