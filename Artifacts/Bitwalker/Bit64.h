
#ifndef BIT64_H_INCLUDED
#define BIT64_H_INCLUDED

#include "FramaCBits.h"

/*@
   requires pre: pos < 64;

   assigns \nothing;

   ensures set_bit: \result != 0 <==> LeftBit64(value, pos);
*/
int PeekBit64(uint64_t value, uint32_t pos);


/*@
    requires pre: pos < 64;

    assigns \nothing;

    ensures left: \forall integer i; 0 <= i < pos ==>  (LeftBit64(\result, i) <==> LeftBit64(value, i));

    ensures set_bit:  flag != 0  <==>  LeftBit64(\result, pos);

    ensures right: \forall integer i; pos < i < 64 ==> (LeftBit64(\result, i) <==> LeftBit64(value, i));

*/
uint64_t PokeBit64(uint64_t value, uint32_t pos, int flag);


/*@
    requires pre: length <= 64;

    assigns \nothing;

    ensures  not_set: \result <==> UpperBitsNotSet(value, length);
*/
int UpperBitsNotSet64(uint64_t value, uint32_t length);


#endif  // BIT64_H_INCLUDED

