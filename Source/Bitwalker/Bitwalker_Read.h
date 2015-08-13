
#ifndef BITWALKER_READ_H_INCLUDED
#define BITWALKER_READ_H_INCLUDED

#include "Bitwalker.h"

/*@
  requires  valid:      Readable(addr, size);
  requires  invariant:  BitwalkerInvariant(size, bitpos, length);
  requires  normal:     NormalBitwalker(size, bitpos, length);

  assigns   \nothing;

  ensures   equal:      EqualBits(addr, bitpos, bitpos + length, \result);
  ensures   upper:      UpperBitsNotSet(\result, length);
*/
uint64_t Bitwalker_Read(uint8_t* addr, uint32_t size, uint32_t bitpos, uint32_t length);

#endif // BITWALKER_READ_H_INCLUDED

