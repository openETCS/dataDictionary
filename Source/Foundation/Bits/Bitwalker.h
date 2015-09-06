
#ifndef BITWALKER_H_INCLUDED
#define BITWALKER_H_INCLUDED

#include "BitPredicates.h"

/*@
   predicate Readable{L}(uint8_t* addr, integer size) = \valid_read(addr + (0..size-1));

   predicate Writeable{L}(uint8_t* addr, integer size) = \valid(addr + (0..size-1));

   predicate Invariant{L}(integer size, integer bitpos, integer length) =
       8 * size <= UINT32_MAX         &&
       length <= 64                   &&
       bitpos + length <= UINT32_MAX;

    predicate Normal{L}(integer size, integer bitpos, integer length) =
       bitpos + length <= 8 * size;
*/


/*@
  requires  valid:      Readable(addr, size);
  requires  invariant:  Invariant(size, bitpos, length);
  requires  normal:     Normal(size, bitpos, length);

  assigns   \nothing;

  ensures   equal:      EqualBits(addr, bitpos, bitpos + length, \result);
  ensures   upper:      UpperBitsNotSet(\result, length);
*/
uint64_t Bitwalker_Read(uint8_t* addr, uint32_t size, uint32_t bitpos, uint32_t length);



/*@
  requires valid:      Writeable(addr, size);
  requires invariant:  Invariant(size, bitpos, length);
  requires normal:     Normal(size, bitpos, length);
  requires upper:      UpperBitsNotSet(value, length);

  assigns addr[0..size-1];

  ensures  left:       Unchanged{Here,Old}(addr, 0, bitpos);
  ensures  middle:     EqualBits(addr, bitpos, bitpos + length, value);
  ensures  right:      Unchanged{Here,Old}(addr, bitpos + length, 8 * size);
*/
void Bitwalker_Write(uint8_t* addr, uint32_t size, uint32_t bitpos, uint32_t length, uint64_t value);


#endif // BITWALKER_H_INCLUDED

