
#ifndef BITWALKER_WRITE_H_INCLUDED
#define BITWALKER_WRITE_H_INCLUDED

#include "Bitwalker.h"

/*@
  requires valid:      Writeable(addr, size);
  requires invariant:  BitwalkerInvariant(size, bitpos, length);
  requires normal:     NormalBitwalker(size, bitpos, length);
  requires upper:      UpperBitsNotSet(value, length);

  assigns addr[0..size-1];

  ensures  left:       Unchanged{Here,Old}(addr, 0, bitpos);
  ensures  middle:     EqualBits(addr, bitpos, bitpos + length, value);
  ensures  right:      Unchanged{Here,Old}(addr, bitpos + length, 8 * size);
*/
void Bitwalker_Write(uint8_t* addr, uint32_t size, uint32_t bitpos, uint32_t length, uint64_t value);

#endif // BITWALKER_WRITE_H_INCLUDED

