
#ifndef Bit64_defined
#define Bit64_defined

#include "Bits.h"
#include <stdint.h>

/*@
   requires 0 <= left_index < 64;

   assigns \nothing;

   ensures (\result != 0) <==> LeftBit64(value, left_index);
*/
int PeekBit64(uint64_t value, unsigned int left_index);



/*@
    requires left_index < 64;

    assigns \nothing;

    ensures \forall integer i; (0 <= i < left_index) ==>
                (LeftBit64(\result, i) <==> LeftBit64(value, i));

    ensures ((flag != 0)  <==>  LeftBit64(\result, left_index));

    ensures \forall integer i; (left_index < i < 64) ==>
                (LeftBit64(\result, i) <==> LeftBit64(value, i));
*/
uint64_t PokeBit64(uint64_t value, unsigned int left_index, int flag);

#endif

