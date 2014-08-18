
#ifndef PeekThenPoke_defined
#define PeekThenPoke_defined

#include "Bitwalker.h"

/*@
    requires \valid(Bitstream + (0..BitstreamSize-1));
    requires 8 * BitstreamSize <= UINT_MAX;
    requires 0 <= Length < 64;
    requires Start + Length <= 8 * BitstreamSize;

    assigns Bitstream[0..BitstreamSize-1];

    ensures \result == 0;

    ensures \forall integer i; 0 <= i < 8 * BitstreamSize ==>
         (LeftBitInStream(Bitstream, i) <==> \old(LeftBitInStream(Bitstream, i)));
*/
int PeekThenPoke(unsigned int Start,
                 unsigned int Length,
                 uint8_t*     Bitstream,
                 unsigned int BitstreamSize);

#endif

