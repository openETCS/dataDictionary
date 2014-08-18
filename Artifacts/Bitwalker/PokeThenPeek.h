
#ifndef PokeThenPeek_defined
#define PokeThenPeek_defined

#include "Bitwalker.h"

/*@
    requires \valid(Bitstream + (0..BitstreamSize-1));
    requires 8 * BitstreamSize <= UINT_MAX;
    requires 0 <= Length < 64;
    requires Start + Length <= 8 * BitstreamSize;
    requires Value < (1 << Length);

    assigns Bitstream[0..BitstreamSize-1];

    ensures \result == Value;
*/
uint64_t PokeThenPeek(unsigned int Start,
                      unsigned int Length,
                      uint8_t*     Bitstream,
                      unsigned int BitstreamSize,
                      uint64_t     Value);

#endif

