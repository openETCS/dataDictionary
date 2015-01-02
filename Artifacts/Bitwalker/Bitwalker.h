
#ifndef BITWALKER_H_INCLUDED
#define BITWALKER_H_INCLUDED

#include "FramaCBits.h"

/*@ predicate
      NormalBitwalker{L}(integer size, integer bitpos, integer length)
        = bitpos + length <= 8 * size;
*/


/*@
  requires  bit_size:     8 * size <= UINT32_MAX;
  requires  max_pos:      bitpos + length <= UINT32_MAX;

  assigns \nothing;

  ensures \result <==> NormalBitwalker(size, bitpos, length);
*/
int NormalBitwalker(uint32_t size, uint32_t bitpos, uint32_t length);


#endif // BITWALKER_H_INCLUDED

