
#ifndef BITWALKER_H_INCLUDED
#define BITWALKER_H_INCLUDED

#include "FramaCBits.h"

/*@
   predicate Readable{L}(uint8_t* addr, integer size) = \valid_read(addr + (0..size-1));

   predicate Writeable{L}(uint8_t* addr, integer size) = \valid(addr + (0..size-1));

   predicate BitwalkerInvariant{L}(integer size, integer bitpos, integer length) =
       8 * size <= UINT32_MAX         &&
       length <= 64                   &&
       bitpos + length <= UINT32_MAX;

    predicate NormalBitwalker{L}(integer size, integer bitpos, integer length) =
       bitpos + length <= 8 * size;
*/


/*@
  requires  BitwalkerInvariant(size, bitpos, length);

  assigns \nothing;

  ensures \result <==> NormalBitwalker(size, bitpos, length);
*/
int NormalBitwalker(uint32_t size, uint32_t bitpos, uint32_t length);

#endif // BITWALKER_H_INCLUDED

