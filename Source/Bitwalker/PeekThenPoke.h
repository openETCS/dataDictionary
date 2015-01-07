
#ifndef PEEKTHENPOKE_H_INCLUDED
#define PEEKTHENPOKE_H_INCLUDED

#include "Bitwalker.h"

/*@
    requires valid:      Writeable(addr, size);

    requires invariant:  BitwalkerInvariant(size, bitpos, length);

    requires normal:     NormalBitwalker(size, bitpos, length);

    assigns addr[0..size-1];

    ensures result_zero: \result == 0;

    ensures unchanged:   EqualBits{Here,Old}(addr, 0, 8*size);
*/
int PeekThenPoke(uint8_t* addr, uint32_t size, uint32_t bitpos, uint32_t length);

#endif // PEEKTHENPOKE_H_INCLUDED

