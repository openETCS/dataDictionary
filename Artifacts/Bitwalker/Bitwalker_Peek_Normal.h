
#ifndef BITWALKER_PEEK_NORMAL_H_INCLUDED
#define BITWALKER_PEEK_NORMAL_H_INCLUDED

#include "Bitwalker.h"

/*@
  requires  array_length: \valid_read(addr + (0..size-1));
  requires  max_length:   length <= 64;
  requires  bit_size:     8 * size <= UINT32_MAX;
  requires  max_pos:      bitpos + length <= 8 * size;

  assigns \nothing;

  ensures copied:    EqualBits64(addr, bitpos, bitpos + length, \result);

  ensures not_set:   UpperBitsNotSet(\result, length);
*/
uint64_t Bitwalker_Peek_Normal(uint8_t* addr, uint32_t size, uint32_t bitpos, uint32_t length);

#endif // BITWALKER_PEEK_NORMAL_H_INCLUDED

