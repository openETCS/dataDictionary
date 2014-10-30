
#ifndef PokeThenPeek_defined
#define PokeThenPeek_defined

#include "BitsFramaC.h"

/*@
    requires \valid(Bitstream + (0..BitstreamSize-1));
    requires 8 * BitstreamSize <= UINT_MAX;
    requires 0 <= Length < 64;
    requires Start + Length <= 8 * BitstreamSize;
    requires Value < (1 << Length);

    assigns Bitstream[0..BitstreamSize-1];

    ensures \result == Value;
*/
uint64_t PokeThenPeek(uint32_t  Start,
                      uint32_t  Length,
                      uint8_t*  Bitstream,
                      uint32_t  BitstreamSize,
                      uint64_t  Value);

#endif

