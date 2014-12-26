
#ifndef BIT64_H_INCLUDED
#define BIT64_H_INCLUDED

#include "FramaCBits.h"

/*@
   requires pre: left < 64;

   assigns \nothing;

   ensures set_bit: \result != 0 <==> LeftBit64(value, left);
*/
int PeekBit64(uint64_t value, uint32_t left);


/*@
    requires pre: pos < 64;

    assigns \nothing;

    ensures unchanged_bits: \forall integer i; (0 <= i < 64  &&  i != pos) ==>
                (LeftBit64(\result, i) <==> LeftBit64(value, i));

    ensures set_bit:  flag != 0  <==>  LeftBit64(\result, pos);
*/
uint64_t PokeBit64(uint64_t value, uint32_t pos, int flag);


/*@
    requires pre: length <= 64;

    assigns \nothing;

    ensures  not_set: \result <==> UpperBitsNotSet(value, length);
*/
int UpperBitsNotSet64(uint64_t value, uint32_t length);


#endif  // BIT64_H_INCLUDED

