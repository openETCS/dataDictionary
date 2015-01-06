
#ifndef POKETHENPEEK_H_INCLUDED
#define POKETHENPEEK_H_INCLUDED

#include "Bitwalker.h"

/*@
    requires valid:      Writeable(addr, size);

    requires invariant:  BitwalkerInvariant(size, bitpos, length);

    requires normal:     NormalBitwalker(size, bitpos, length);

    requires upper:      UpperBitsNotSet(value, length);

    assigns addr[0..size-1];

    ensures result_value:  \result == value;
*/
uint64_t PokeThenPeek(uint8_t* addr, uint32_t size, uint32_t bitpos, uint32_t length, uint64_t value);

#endif // POKETHENPEEK_H_INCLUDED

